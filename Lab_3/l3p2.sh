#!/bin/bash

if [ $# -ne 3 ]
then
    echo "Usage: ./calc.sh num1 op num2"
    exit
fi

n1=$1
op=$2
n2=$3

case $op in
    +) res=$((n1 + n2)) ;;
    -) res=$((n1 - n2)) ;;
    x) res=$((n1 * n2)) ;;
    /) res=$((n1 / n2)) ;;
    *) echo "Invalid operator"
       exit ;;
esac

echo "Result: $res"