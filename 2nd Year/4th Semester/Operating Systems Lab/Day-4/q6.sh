#!/bin/bash
b='='
height=20

for i in {1..50}
do
    for j in {1..50}
    do
        tput cup $i $j  # Move cursor to position (i, j)
        echo -n "$b"    # Print the ball
        sleep 1      # Sleep to control speed
        tput cup $i $j  # Move cursor to position (i, j) again
        echo -n " "     # Clear the previous ball by printing a space
    done
done
