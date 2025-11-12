#!/bin/bash

add_nums() {
    sum=$(($1 + $2 + $3))
    echo "Sum is: $sum"
}

echo "Enter numbers:"
read a b c
add_nums $a $b $c

