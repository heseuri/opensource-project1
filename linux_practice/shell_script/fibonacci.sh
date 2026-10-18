#!/bin/bash

a=0
b=1

for ((i=1; i<=10; i++))
do
    echo -n "$a "

    let next=a+b
    a=$b
    b=$next
done

echo ""
