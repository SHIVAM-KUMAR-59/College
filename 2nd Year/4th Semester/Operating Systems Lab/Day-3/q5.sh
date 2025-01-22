# WAP that will keep latest 'n' files.

#!/bin/bash
n=$1
b=$(ls -t)
for i in $b
do
    if [ $n -gt 0 ]
    then
        echo $i
        n=$((n - 1))
    fi
done