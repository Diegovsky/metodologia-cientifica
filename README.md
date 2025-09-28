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

`codigo/gen.fish` -  para gerar os resultados do tree sort quando a entrada é:
 - aleatória (random)
 - ordenada (sorted)
 - ordenada reversa (revsorted)

`codigo/gen-all.fish` - para gerar os resultados do tree sort em comparação com o selection e insertion sorts.

# Como Gerar Os Gráficos
É necessário ter instalado: `numpy matplotlib yaml` no Python 3 para executar os programas:

`codigo/plot.py <entrada>` - para gerar o gráfico de alguma entrada designada em parentesis na seção anterior.

