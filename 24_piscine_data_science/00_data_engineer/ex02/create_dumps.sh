export PGPASSWORD='mysecretpassword'
for file in /00_data_engineer/ex02/customer/*
do
    file_name=$(basename $file)
    filename_without_extension="${file_name%.*}"
    
    pg_dump -U ngasco -h localhost -s piscineds -t $filename_without_extension > table.$filename_without_extension.dmp
    
    if [ $? -ne 0 ]; then
        echo "Error creating dump of table $filename_without_extension"
        exit 1
    fi
    
    echo "Creating dump of table $filename_without_extension"
    
    
done