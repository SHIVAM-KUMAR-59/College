# WAP that will distribute all files into different sub folders based on maximum size of folder

#!/bin/bash
dir=$1
size=$2
counter=1
curr_size=0
subfolder="subfolder_$counter"
mkdir -p "$subfolder"
for file in "$dir"/*; do
do 
    fsize=$(du -k "$file" | cut -f1)
    if [ $(($curr_size + $fsize)) -gt $(($size)) ]
    then
        counter=$((counter + 1))
        curr_size=0
        subfolder="subfolder_$counter"
        mkdir -p "$subfolder"
    fi
    mv "$file" "$subfolder"
    curr_size=$((curr_size + $fsize))
done
