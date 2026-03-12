#!/bin/bash
while true
do
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Power"
    echo "6. Factorial"
    echo "7. GCD"
    echo "8. LCM"
    echo "9. Exit"
    echo "Enter Choice:"
    read -r ch
    
    if [ "$ch" -eq 9 ]
    then
        exit
    fi
    
    if [ "$ch" -eq 6 ]
    then
        echo "Enter Number:"
        read -r n1
    else
        echo "Enter Two Numbers:"
        read -r n1 n2
    fi
    
    case $ch in
        1) 
            res=$((n1 + n2))
            echo "Result: $res" 
            ;;
        2) 
            res=$((n1 - n2))
            echo "Result: $res" 
            ;;
        3) 
            res=$((n1 * n2))
            echo "Result: $res" 
            ;;
        4) 
            if [ "$n2" -eq 0 ]
            then
                echo "Error: Div by Zero"
            else
                res=$((n1 / n2))
                echo "Result: $res"
            fi 
            ;;
        5) 
            res=$((n1 ** n2))
            echo "Result: $res" 
            ;;
        6) 
            fact=1
            for ((i=1; i<=n1; i++))
            do
                fact=$((fact * i))
            done
            echo "Factorial: $fact" 
            ;;
        7) 
            m="$n1"
            n="$n2"
            while [ "$n" -ne 0 ]
            do
                t="$n"
                n=$((m % n))
                m=$t
            done
            echo "GCD: $m" 
            ;;
        8) 
            m="$n1"
            n="$n2"
            while [ $n -ne 0 ]
            do
                t=$n
                n=$((m % n))
                m=$t
            done
            gcd=$m
            lcm=$(( (n1 * n2) / gcd ))
            echo "LCM: $lcm" 
            ;;
        *) 
            echo "Invalid Choice" 
            ;;
    esac
done