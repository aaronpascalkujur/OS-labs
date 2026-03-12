# The Even/Odd Checker

#!/bin/bash

echo "Enter a number: "
read num
rem=$((num % 2))
if [ $rem -eq 0 ]; then
echo "Its a even number"
else
echo "Its a odd number"
fi
