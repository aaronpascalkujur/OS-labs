#!/bin/bash

echo "Enter Employee Name:"
read -r name
echo "Enter Hours Worked:"
read -r hours
echo "Enter Hourly Wage:"
read -r wage

echo "1. Calculate and display total salary"
echo "2. Display employee details"
echo "3. Exit"
echo "Enter choice:"
read -r ch

case $ch in
    1)
        salary=$((hours * wage))
        echo "Total Salary: $salary"
        ;;
    2)
        echo "Employee Name: $name"
        echo "Hours Worked: $hours"
        echo "Hourly Wage: $wage"
        ;;
    3)
        exit
        ;;
    *)
        echo "Invalid choice"
        ;;
esac