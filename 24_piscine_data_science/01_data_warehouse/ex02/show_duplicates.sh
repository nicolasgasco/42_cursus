#!/bin/bash

psql -U ngasco -d piscineds -h localhost -c "SELECT ctid
FROM(
    SELECT
        *,
        ctid,
        row_number() OVER (PARTITION BY event_time, event_type, product_id, price, user_id, user_session ORDER BY ctid)
    FROM customers
)s
WHERE row_number >= 2;"

if [ $? -ne 0 ]; then
    echo "Error showing duplicates"
    exit 1
fi