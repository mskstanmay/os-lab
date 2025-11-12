#!/bin/bash
read -p "Enter num: " n
sum=0
echo "Enter $n numbers: "
for ((i=1; i<=n; i++))
do 
    read -p "Number $i : " num
    sum=$((sum + num))
done
echo "The sum is: $sum"

