echo "Enter a number:"
read num
if [ $((num % 2)) -eq 0 ]
then
echo "$num is an Even number."
else
echo "$num is an Odd number."
fi
