
psql -U ngasco -d piscineds -h localhost -c "COPY (
    SELECT order_count, COUNT(user_id) AS customer_count, SUM(total_price) AS total_price
    FROM (
        SELECT user_id, COUNT(event_type) AS order_count, SUM(price) AS total_price
        FROM customers
        WHERE event_type = 'purchase'
        GROUP BY user_id
    ) AS subquery
    GROUP BY order_count
    ORDER BY order_count
) TO '/02_data_analyst/ex03/customers_by_frequency.csv' WITH CSV HEADER;"