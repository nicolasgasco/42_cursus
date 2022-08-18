for file in ./tests/validation_scripts/*.sh
do
    sh "$file"
    if [ "$?" = "1" ]
    then
        exit 1
    fi
done
