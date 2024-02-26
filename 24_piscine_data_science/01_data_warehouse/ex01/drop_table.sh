#!/bin/bash

echo "Dropping table customers"
psql -U ngasco -d piscineds -h localhost -c "DROP TABLE IF EXISTS customers;"