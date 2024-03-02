
psql -U ngasco -d piscineds -h localhost -c "COPY (
    SELECT DATE(event_time) AS date, SUM(price) AS total_price
    FROM customers
    GROUP BY DATE(event_time)
    ORDER BY DATE(event_time)
) TO '/02_data_analyst/ex01/purchases_by_day.csv' WITH CSV HEADER;"