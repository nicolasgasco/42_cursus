#!/bin/sh
# Specify the folder path
folder="/workspaces/42_cursus/22_libasm"

# Loop through each file in the folder
for file in "$folder"/*; do
    # Check if the file is a regular file and ends with ".s"
    if [ -f "$file" ] && [ "${file##*.}" = "s" ]; then
        # Remove _
        sed -i "s/ft/_ft/g" "$file"
    fi
done
