#!/bin/sh

# For Linux, you cannnot reference functions written in assembly that starts with an underscore
# For Intel MacOs, it's the opposite
# This script removes the underscore from the function names in the assembly files

folder="/workspaces/42_cursus/22_libasm/src"

# Loop through each file in the folder
for file in "$folder"/*; do
    # Check if the file is a regular file and ends with ".s"
    if [ -f "$file" ] && [ "${file##*.}" = "s" ]; then
        # Remove _
        sed -i "s/_ft/ft/g" "$file"
    fi
done
