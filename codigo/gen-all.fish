#!/usr/bin/env fish
function gen-elements -a i
    perl -E 'for (1..'$i') { print int(rand(1e9)), " " } say ""'
end

if test "$argv[1]" = worst
    echo $argv[1]
    function gen-elements -a i
        perl -E 'for (1..'$i') { print '$i'-$_, " " } say ""'
    end
end

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
        gen-elements $i | $command
    end >"dados/results-$algo.yml"
end
