#!/bin/bash
a='O'
width=50

for j in {1..50}
do
    for i in {1..50}
    do
        tput cup $i $j  # Move cursor to position (i, j)
        echo -n "$a"    # Print the brick
        sleep 1      # Sleep to control speed
        tput cup $i $j  # Move cursor to position (i, j) again
        echo -n " "     # Clear the previous brick by printing a space
    done
done
