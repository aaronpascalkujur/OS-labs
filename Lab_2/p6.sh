#!/bin/bash

echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Exit"
echo "Enter your choice:"
read ch

if [ $ch -eq 5 ]
then
    exit
fi

echo "Enter two numbers:"
read n1 n2

case $ch in
    1)
        res=$((n1 + n2))
        echo "Sum: $res"
        ;;
    2)
        res=$((n1 - n2))
        echo "Difference: $res"
        ;;
    3)
        res=$((n1 * n2))
        echo "Product: $res"
        ;;
    4)
        if [ $n2 -eq 0 ]
        then
            echo "Error: Division by zero"
        else
            res=$((n1 / n2))
            echo "Quotient: $res"
        fi
        ;;
    *)
        echo "Invalid choice"
        ;;
esac