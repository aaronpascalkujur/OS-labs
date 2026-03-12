#!/bin/bash

generate_fib() {
    limit=$1
    a=0
    b=1
    echo "Fibonacci Series up to $limit:"
    echo "$a"
    
    while [ $b -le $limit ]
    do
        echo "$b"
        fn=$((a + b))
        a=$b
        b=$fn
    done
}

echo "Enter limit n:"
read n
generate_fib $n