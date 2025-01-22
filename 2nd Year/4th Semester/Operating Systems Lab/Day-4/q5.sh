#!/bin/bash
for i in {10..20}
do
    tput cup $i 20
    echo "O"
    tput cup $((i-1)) 20
    echo " "   
    sleep 0.4
    tput cup 20 $i
    echo "=="
    tput cup 20 $((i-1))
    echo " "
    sleep 0.4
done
