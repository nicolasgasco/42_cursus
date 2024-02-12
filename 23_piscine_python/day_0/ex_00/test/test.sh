#!/bin/bash

python ../Hello.py | cat -e > test_output
echo "Running diff between test_output and expected_output"
diff test_output expected_output
rm test_output