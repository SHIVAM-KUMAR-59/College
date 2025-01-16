# Save ps -el in a file and extract unique priority and display it

#!/bin/bash
ps -el > ps_output.txt
cut -c 19-21 ps_output.txt | sort | uniq