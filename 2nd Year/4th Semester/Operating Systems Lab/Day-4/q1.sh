# WAP to show the usability of fprintf, fscanf, write, read, system and sprintf, strtok function

#!/bin/bash
for i in {1..5}
do
    for j in {1..5}
    do
        tput cup $i $j
        echo "ABC"
        tput cup clear
        sleep 0.75
    done
done