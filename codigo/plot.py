#!/usr/bin/env python3
import sys
import matplotlib.pyplot as plt
import numpy as np
import yaml

input_name = sys.argv[1]

data = yaml.safe_load(open(f"dados/results-{input_name}.yml", "r"))
x = np.array([float(key) for key in data.keys()])
real = np.array([float(x["real"].split(" ")[0]) for x in data.values()])

logx = np.log(x)
logy = np.log(real + 1e-12)
slope, intercept = np.polyfit(logx, logy, 1)
fit_y = np.exp(intercept) * x**slope

plt.figure(figsize=(8, 6))
plt.plot(x, real, "o", label="Tempo")
plt.plot(x, fit_y, "-", label="Tempo Extrapolado")

plt.xlabel("Tamanho da Entrada (N)")
plt.ylabel("Tempo (s)")
plt.xscale("log")
plt.yscale("log")
plt.title(f"Tempo de Execução Vs. Tamanho da Entrada ({input_name})")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig(f"dados/{input_name}.svg")
