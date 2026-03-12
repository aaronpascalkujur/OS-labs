#!/bin/bash

echo "Enter your array elements: "
read -a arr
len=${#arr[@]}
is_palin=1
for (( i=0; i<len/2; i++ )); do
    if [ ${arr[$i]} -ne ${arr[$((len - i - 1))]}]

done