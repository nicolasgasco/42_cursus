psql -U ngasco -d piscineds -h localhost -c "COPY (
    SELECT price, COUNT(product_id) AS product_count
    FROM customers
    WHERE event_type = 'purchase'
    GROUP BY price
    ORDER BY price
) TO '/02_data_analyst/ex02/items_per_price.csv' WITH CSV HEADER;"


