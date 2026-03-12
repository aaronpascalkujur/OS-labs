#!/bin/bash

# Constraint: Validate non-negative input
if [ $1 -lt 0 ]; then 
    echo "Error: Input must be non-negative"
    exit 1
fi

# Constraint: No loops for factorial (Recursion)
fact() {
    if [ $1 -le 1 ]; then 
        echo 1
    else 
        echo $(($1 * $(fact $(($1-1)))))
    fi
}

# Recursion for Fibonacci
fibo() {
    if [ $1 -le 0 ]; then echo 0
    elif [ $1 -eq 1 ]; then echo 1
    else echo $(($(fibo $(($1-1))) + $(fibo $(($1-2)))))
    fi
}

echo "Factorial of $1 is $(fact $1)"
echo "Nth Fibonacci number ($1) is $(fibo $1)"

echo -n "Fibonacci Series up to $1 terms: "
for ((i=0; i<$1; i++)); do
    echo -n "$(fibo $i) "
done
echo ""