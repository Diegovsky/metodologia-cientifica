#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
import yaml
import sys

name = sys.argv[1] if len(sys.argv) > 1 else ""

plt.figure(figsize=(8, 6))
for algo in ["treesort", "insertionsort", "selectionsort"]:
    data = yaml.safe_load(open(f"dados/results-{algo}.yml", "r"))
    x = np.array([float(key) for key in data.keys()])
    real = np.array([float(x["real"].split(" ")[0]) for x in data.values()])

    logx = np.log(x)
    logy = np.log(real + 1e-12)
    slope, intercept = np.polyfit(logx, logy, 1)
    fit_y = np.exp(intercept) * x**slope

    plt.plot(x, fit_y, "-", label=algo)

plt.xlabel("Input size (N)")
plt.ylabel("Time (s)")
plt.xscale("log")
plt.yscale("log")
plt.title("Todos os Algoritmos" + f" ({name})" if name else "")
plt.legend()
plt.grid(True)
plt.tight_layout()
if name:
    filename = f"dados/all-{name}.svg"
else:
    filename = "dados/all.svg"


plt.savefig(filename)
