
psql -U ngasco -d piscineds -h localhost -c "COPY (
    SELECT DATE_TRUNC('month', event_time) AS month, SUM(price) AS total_price
    FROM customers
    GROUP BY DATE_TRUNC('month', event_time)
    ORDER BY DATE_TRUNC('month', event_time)
) TO '/02_data_analyst/ex01/sales_by_month.csv' WITH CSV HEADER;"