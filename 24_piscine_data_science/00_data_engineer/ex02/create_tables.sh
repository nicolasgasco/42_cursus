export PGPASSWORD='mysecretpassword'
for file in /00_data_engineer/ex02/customer/*
do
    file_name=$(basename $file)
    filename_without_extension="${file_name%.*}"
    
    
    psql -U ngasco -d piscineds -h localhost -c "CREATE TABLE $filename_without_extension (
        event_time TIMESTAMPTZ,
        event_type VARCHAR(50),
        product_id INT,
        price NUMERIC(10, 2),
        user_id BIGINT,
        user_session uuid
    );"
    
    if [ $? -ne 0 ]; then
        echo "Error creating table $filename_without_extension"
        exit 1
    fi
    
    echo "Table $filename_without_extension created"
    
    psql -U ngasco -d piscineds -h localhost -c "COPY $filename_without_extension(event_time, event_type, product_id, price, user_id, user_session)
    FROM '/00_data_engineer/ex02/customer/$file_name'
    DELIMITER ','
    CSV HEADER;"
    
    if [ $? -ne 0 ]; then
        echo "Error copying data to table $filename_without_extension"
        exit 1
    fi
    
    echo "Data copied to table $filename_without_extension"
    
done