#!/usr/bin/env fish
set command codigo/treesort

if ! test -f $command
    echo 'Algoritmo não encontrado'
    exit -1
end

set numbers (cat dados/numbers.in | perl -nE 'chomp; say split if $_ > 0')

for i in $numbers

    echo "Running $i..." >&2
    echo "$i:"
    perl -E 'for (1..'$i') { print int(rand(1e9)), " " } say ""' | $command
end >"dados/results-random.yml"

for i in $numbers
    echo "Running $i..." >&2
    echo "$i:"
    perl -E 'for (1..'$i') { print $_, " " } say ""' | $command
end >"dados/results-sorted.yml"

for i in $numbers
    echo "Running $i..." >&2
    echo "$i:"
    perl -E 'for (1..'$i') { print '$i'-$_, " " } say ""' | $command
end >"dados/results-revsorted.yml"
