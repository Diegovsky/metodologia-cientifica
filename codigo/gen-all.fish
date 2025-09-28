#!/usr/bin/env fish
for algo in {tree,insertion,selection}sort

    set command codigo/$algo

    if ! test -f $command
        echo 'Algoritmo não encontrado'
        exit -1
    end

    echo $algo >&2
    for i in (cat dados/numbers-all.in | perl -nE 'chomp; say split if $_ > 0')

        echo "Running $i..." >&2
        echo "$i:"
        perl -E 'for (1..'$i') { print int(rand(1e9)), " " } say ""' | $command
    end >"dados/results-$algo.yml"
end
