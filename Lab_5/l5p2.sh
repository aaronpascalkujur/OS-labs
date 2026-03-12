#!/bin/bash
echo "Enter array elements:"
read -a arr
echo "Frequency of elements:"
printf "%s\n" "${arr[@]}" | sort | uniq -c | awk '{print $2 " occurs " $1 " times"}'