# Program to find sum of all the numbers passed as command line arguments
#!/bin/bash

sum=0
for num in $@ 
do
    sum=$((sum + num))
done

echo "The sum of all numbers is: $sum"
