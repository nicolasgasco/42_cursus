#!/bin/sh

# For Linux, you cannnot reference functions written in assembly that starts with an underscore
# For Intel MacOs, it's the opposite
# This script removes the underscore from the function names in the assembly files

folder="/home/ngasco/Documents/42_cursus/22_libasm/src"

# Loop through each file in the folder
for file in "$folder"/*; do
    # Check if the file is a regular file and ends with ".s"
    if [ -f "$file" ] && [ "${file##*.}" = "s" ]; then
        sed -i "s/_ft/ft/g" "$file"
        sed -i "s/_malloc/malloc/g" "$file"
        sed -i 's/call ___error/call __errno_location WRT ..plt/g' "$file"
        sed -i 's/extern  ___error/extern  __errno_location/g' "$file"
        sed -i 's/call malloc/call malloc WRT ..plt/g' "$file"
        sed -i 's/extern  malloc/extern  malloc/g' "$file"
        sed -i 's/%define WRITE_SYSCALL 0x2000004/%define WRITE_SYSCALL 1/g' "$file"
        sed -i 's/%define READ_SYSCALL 0x2000003/%define READ_SYSCALL 0/g' "$file"
        
    fi
done
