#!/bin/sh

# For Linux, you cannnot reference functions written in assembly that starts with an underscore
# For Intel MacOs, it's the opposite
# This script removes the underscore from the function names in the assembly files

folder="/Users/ngasco/Documents/42_cursus/22_libasm/src"

# Loop through each file in the folder
for file in "$folder"/*; do
    # Check if the file is a regular file and ends with ".s"
    if [ -f "$file" ] && [ "${file##*.}" = "s" ]; then
        sed -i'' -e 's/WRT ..plt//g' "$file"
        sed -i'' -e 's/__errno_location/___error/g' "$file"
    fi
done
