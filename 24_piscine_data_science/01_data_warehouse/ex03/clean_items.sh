#!/bin/bash

psql -U ngasco -d piscineds -h localhost -c "DELETE FROM items WHERE category_id IS NULL;"

if [ $? -ne 0 ]; then
    echo "Error cleaning items table"
    exit 1
fi

echo "Items table cleaned up"