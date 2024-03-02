
psql -U ngasco -d piscineds -h localhost -c "COPY (
    SELECT *
    FROM customers
) TO '/02_data_analyst/ex00/customers.csv' WITH CSV HEADER;"