# Display even numbers present in a file

#!/bin/bash
#!/bin/bash

file="nums.txt"
echo "Even numbers in $file:"

# Get the total number of lines in the file
total_lines=$(wc -l < "$file")

# Iterate through each line using head and tail
for ((i=1; i<=total_lines; i++))
do
    # Extract the current line
    number=$(head -n "$i" "$file" | tail -n 1)

    # Check if the number is even
    if [ $((number % 2)) -eq 0 ]
    then
        echo "$number"
    fi
done
