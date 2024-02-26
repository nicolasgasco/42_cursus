#!/bin/bash

echo "Creating items table"
psql -U ngasco -d piscineds -h localhost -c "CREATE TABLE items (
    id SERIAL PRIMARY KEY,
    product_id INT,
    category_id BIGINT,
    category_code TEXT,
    brand TEXT
);"

if [ $? -ne 0 ]; then
    echo "Error creating items table"
    exit 1
fi


psql -U ngasco -d piscineds -h localhost -c "COPY items(product_id, category_id, category_code, brand)
    FROM '/00_data_engineer/ex04/item.csv'
    DELIMITER ','
CSV HEADER;"