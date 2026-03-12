#!/bin/bash

echo "Enter Consumer ID:"
read -r id
echo "Enter Consumer Name:"
read -r name
echo "Enter Units Consumed:"
read -r units

if [ "$units" -le 100 ]
then
    charge=$(echo "$units * 1.50" | bc)
elif [ "$units" -le 300 ]
then
    charge=$(echo "100 * 1.50 + ($units - 100) * 2.50" | bc)
else
    charge=$(echo "100 * 1.50 + 200 * 2.50 + ($units - 300) * 4.00" | bc)
fi

if [ "$(echo "$charge > 1000" | bc)" -eq 1 ]
then
    surcharge=$(echo "$charge * 0.10" | bc)
    total=$(echo "$charge + $surcharge" | bc)
else
    total=$charge
fi

echo "--------------------------------"
echo "Electricity Bill"
echo "Consumer ID    : $id"
echo "Name           : $name"
echo "Units Consumed : $units"
echo "Total Bill     : Rs. $total"
echo "--------------------------------"