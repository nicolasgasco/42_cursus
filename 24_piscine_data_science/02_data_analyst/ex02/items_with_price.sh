
psql -U ngasco -d piscineds -h localhost -c "COPY (
    SELECT DISTINCT product_id, price
    FROM customers
    WHERE event_type = 'purchase'
) TO '/02_data_analyst/ex02/items_with_price.csv' WITH CSV HEADER;"




