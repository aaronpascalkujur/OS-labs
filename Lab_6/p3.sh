#!/bin/bash

if [ $# -ne 3 ]; then 
    echo "Usage: ./p3.sh num1 operator num2"
    exit 1
fi

# Constraint: Use command-line arguments and bc for floating operations
case $2 in
    +) echo "$1 + $3" | bc -l ;;
    -) echo "$1 - $3" | bc -l ;;
    x|\*) echo "$1 * $3" | bc -l ;; 
    /)
        # Constraint: Division by zero handling
        if [ "$3" == "0" ]; then 
            echo "Error: Division by zero!"
        else 
            echo "scale=2; $1 / $3" | bc -l
        fi
        ;;
    %) echo "$1 % $3" | bc ;;
    ^) echo "$1 ^ $3" | bc -l ;;
    *) echo "Invalid operator. Use +, -, x, /, %, ^" ;;
esac