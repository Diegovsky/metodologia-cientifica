# Como compilar
```sh
cd codigos
make
```

# Como rodar
```sh
<treesort|selectionsort|insertionsort> <arquivo>
# ou
programa | <treesort|selectionsort|insertionsort>
```

# Como Gerar Os Resultados
É necessário haver a shell fish instalada para executar os programas:

`codigo/gen.fish` - para gerar os resultados do tree sort quando a entrada é:
 - aleatória (random)
 - ordenada (sorted)
 - ordenada reversa (revsorted)

`codigo/gen-all.fish [worst]` - para gerar os resultados do tree sort em comparação com o selection e insertion sorts. Passe como parâmetro 'worst' para gerar a comparação com os piores casos.

# Como Gerar Os Gráficos
É necessário ter instalado: `numpy matplotlib yaml` no Python 3 para executar os programas:

`codigo/plot.py <entrada>` - para gerar o gráfico de alguma entrada designada em parentesis na seção anterior.

`codigo/plot-all.py [worst]` - para gerar o gráfico de comparação entre todos os algoritmos, gerado pelo `gen-all.fish` anteriormente. Passe como parâmetro 'worst' para gerar a comparação entre os piores casos.

# Como Gerar Gŕafico de Consumo de Memória
O seguinte script gera um arquivo `input.txt` com 6e7 números aleatórios, e então executa a ferramenta massif do valgrind para gerar um relatório.
```sh
perl -E 'for (1..6e7) { print int(rand(1e9)), " " } say ""' > input.txt
valgrind --tool=massif codigo/treesort input.txt
```

Para obter o gráfico, utiliza-se o programa `massif-visualizer`.
