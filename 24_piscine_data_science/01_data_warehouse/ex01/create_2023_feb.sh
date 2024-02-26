#!/bin/bash

psql -U ngasco -d piscineds -h localhost -c "CREATE TABLE IF NOT EXISTS data_2023_feb (
        event_time TIMESTAMPTZ,
        event_type VARCHAR(50),
        product_id INT,
        price NUMERIC(10, 2),
        user_id BIGINT,
        user_session uuid
);"

if [ $? -ne 0 ]; then
    echo "Error creating table data_2023_feb"
    exit 1
fi

echo "Table data_2023_feb created"


psql -U ngasco -d piscineds -h localhost -c "COPY data_2023_feb(event_time, event_type, product_id, price, user_id, user_session)
    FROM '/01_data_warehouse/ex01/data_2023_feb.csv'
    DELIMITER ','
CSV HEADER;"

if [ $? -ne 0 ]; then
    echo "Error copying data to table data_2023_feb"
    exit 1
fi

echo "Data copied to table data_2023_feb"