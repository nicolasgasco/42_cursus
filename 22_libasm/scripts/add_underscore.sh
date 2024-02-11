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
        # Remove _
        sed -i "s/ft/_ft/g" "$file"
    fi
done
