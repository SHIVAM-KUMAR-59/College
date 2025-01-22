# Read a file that contains different values. WAP to find sum of all even and odd numbers in the  file

#!/bin/bash
even=0
odd=0
a=$(cat num)
for i in $a
do
    if [ $((i % 2)) -eq 0 ]
    then
        even=$((even + i))
    else
        odd=$((odd + i))
    fi
done
echo "Sum of even numbers: $even"
echo "Sum of odd numbers: $odd"