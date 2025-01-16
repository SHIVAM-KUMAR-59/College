# Find the number of 80, 70 and 92 in the table
# 1 DF 80
# 2 RTS 70
# 3 FT 80
# 4 FTI 92
# 5 FT2 80

#!/bin/bash
tr ' ' '\n' | sort | uniq -c | cut -d ' ' -t2,3