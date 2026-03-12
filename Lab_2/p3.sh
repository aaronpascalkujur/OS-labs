nano "Enter the marks 1st Subject"
read a
nano "Enter the marks 2nd Subject"
read b
nano "Enter the marks 3rd Subject"
read c
nano "Enter the marks 4th Subject"
read d
nano "Enter the marks 5th Subject"
read e
total=$((a+b+c+d+e))
per=$((total/5))
echo "Percentage: $per%"
if [ $per -ge 90 ]
then
echo "Grade: A"
echo "Distinction"
elif [ $per -ge 75 ]
then
echo "Grade: B"
elif [ $per -ge 50 ]
then
echo "Grade: C"
else
echo "Grade: F"
echo "Fail"
fi
