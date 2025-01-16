# Display Dec 18 2024 as 18/12/24 format

#!/bin/bash
date="Dec 18 2024"
day=$(echo $date | cut -d ' ' -f2)        # Extract the day
month=$(echo $date | cut -d ' ' -f1)      # Extract the month
year=$(echo $date | cut -d ' ' -f3)       # Extract the year

# Convert the month name to its numeric representation
month_num=$(date -d "1 $month" "+%m")

# Format the new date
new_date="$day/$month_num/$year"

echo $new_date
