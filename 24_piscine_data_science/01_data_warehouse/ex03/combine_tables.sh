#!/bin/bash

psql -U ngasco -d piscineds -h localhost -c "SELECT * FROM customers LEFT JOIN items ON customers.product_id = items.product_id ORDER BY customers.product_id;"

if [ $? -ne 0 ]; then
    echo "Error combining tables"
    exit 1
fi

echo "Tables combined"