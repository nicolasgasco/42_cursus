
psql -U ngasco -d piscineds -h localhost -c "COPY (
    SELECT date, AVG(daily_spent) AS average_spent
    FROM (
        SELECT DATE(event_time) AS date, user_id, SUM(price) AS daily_spent
        FROM customers
        WHERE event_type = 'purchase'
        GROUP BY DATE(event_time), user_id
    ) AS subquery
    GROUP BY date
    ORDER BY date
) TO '/02_data_analyst/ex01/average_spent.csv' WITH CSV HEADER;"