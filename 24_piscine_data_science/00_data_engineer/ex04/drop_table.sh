#!/bin/bash


echo "Dropping table items"

psql -U ngasco -d piscineds -h localhost -c "DROP TABLE IF EXISTS items;"
if [ $? -ne 0 ]; then
    echo "Error dropping table items"
    exit 1
fi

echo "Table items dropped"
