
psql -U ngasco -d piscineds -h localhost -c "COPY (
    SELECT DATE(event_time) AS date, COUNT(DISTINCT user_id) AS unique_users
    FROM customers
    WHERE event_type = 'purchase'
    GROUP BY DATE(event_time)
    ORDER BY DATE(event_time)
) TO '/02_data_analyst/ex01/customers_by_day.csv' WITH CSV HEADER;"