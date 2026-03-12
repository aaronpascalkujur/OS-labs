#!/bin/bash

echo "Enter limit n:"
read n
a=0
b=1

echo "Fibonacci Series:"
echo "$a"

while [ $b -le $n ]
do
    echo "$b"
    fn=$((a + b))
    a=$b
    b=$fn
done