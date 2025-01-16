# Display Dec 18 2024 as 18/12/24 format

#!/bin/bash
date="Dec 18 2024"
split = $(echo $date | cut -d ' ' -f2,3,4)
day = $(echo $split | cut -d ' ' -f1)
month = $(echo $split | cut -d ' ' -f2)
year = $(echo $split | cut -d ' ' -f3)
new_date = $day/$month/$year
echo $new_date