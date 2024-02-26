#!/bin/bash

tables=("data_2022_oct" "data_2022_nov" "data_2022_dec" "data_2023_jan" "data_2023_feb")
first_table=${tables[0]}


psql -U ngasco -d piscineds -h localhost -c "CREATE TABLE IF NOT EXISTS customers AS TABLE $first_table WITH NO DATA;"
if [ $? -ne 0 ]; then
    echo "Error creating items table"
    exit 1
fi
echo "Creating customers table"

psql -U ngasco -d piscineds -h localhost -c "TRUNCATE TABLE customers;"
echo "Truncating customers table"


for table in "${tables[@]}"
do
    psql -U ngasco -d piscineds -h localhost -c "INSERT INTO customers SELECT * FROM $table ON CONFLICT DO NOTHING;"
    if [ $? -ne 0 ]; then
        echo "Error mergin $table table into customers"
        exit 1
    fi
    echo "Merging $table table into customers"
done
