# Display All the files, directories and subdirectories in the current directory in ascending and descending order of their modified date

#!/bin/bash
ls -lt | sort -k6,7 # Ascending Order
ls -lt # Descending Order

