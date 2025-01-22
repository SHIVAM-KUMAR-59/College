# WAP to display all the files in a given directory

#!/bin/bash
a=$1
b=$(cd $a)
echo $(ls $b)