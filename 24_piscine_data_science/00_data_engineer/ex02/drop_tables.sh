#!/bin/bash

export PGPASSWORD='mysecretpassword'
for file in /00_data_engineer/ex02/customer/*
do
    file_name=$(basename $file)
    filename_without_extension="${file_name%.*}"
    
    
    echo "Dropping table $filename_without_extension"
    psql -U ngasco -d piscineds -h localhost -c "DROP TABLE IF EXISTS $filename_without_extension;"
    
    if [ $? -ne 0 ]; then
        echo "Error dropping table $filename_without_extension"
        exit 1
    fi
    
    echo "Table $filename_without_extension dropped"
    
done