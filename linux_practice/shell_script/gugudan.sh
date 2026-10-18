#!/bin/bash

for dan in {2..9}
do
    echo "=== $dan 단 ==="

    for num in {1..9}
    do
        echo "$dan x $num = $((dan * num))"
    done

    echo ""
done
