#!/bin/bash
echo "Enter array elements:"
read -a arr
len=${#arr[@]}
flag=1
for (( i=0; i<len/2; i++ ))
do
if [ "${arr[$i]}" != "${arr[$((len-1-i))]}" ]
then
flag=0
break
fi
done
if [ $flag -eq 1 ]
then
echo "Array is a Palindrome"
else
echo "Array is not a Palindrome"
fi