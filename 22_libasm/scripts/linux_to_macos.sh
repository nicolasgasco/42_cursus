#!/bin/sh

# For Linux, you cannnot reference functions written in assembly that starts with an underscore
# For Intel MacOs, it's the opposite
# This script adds the underscore to the function names in the assembly files
# Once the underscore was already removed from the function names

folder="/workspaces/42_cursus/22_libasm/src"

# Loop through each file in the folder
for file in "$folder"/*; do
    # Check if the file is a regular file and ends with ".s"
    if [ -f "$file" ] && [ "${file##*.}" = "s" ]; then
        sed -i "s/ft/_ft/g" "$file"
        sed -i 's/call __errno_location WRT ..plt/call ___error/g' "$file"
        sed -i 's/extern  __errno_location/extern  ___error/g' "$file"
        sed -i 's/call malloc WRT ..plt/call _malloc/g' "$file"
        sed -i 's/extern  malloc/extern  _malloc/g' "$file"
        sed -i 's/%define WRITE_SYSCALL 1/%define WRITE_SYSCALL 0x2000004/g' "$file"
        sed -i 's/%define READ_SYSCALL 0/%define READ_SYSCALL 0x2000003/g' "$file"
    fi
done
