#!/bin/bash
read -p "Enter num: " n
fact=1
i=1

while true
do
    fact=$((fact * i))
    i=$((i + 1))
    if [ $i -gt $n ]; then
        break
    fi
done

echo "Factorial is $fact"

