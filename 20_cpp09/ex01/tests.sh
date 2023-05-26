#!/bin/bash

make re

test_assertion()
{
    RESULT=$(./RPN "$1" 2>&1)
    if [ "$RESULT" == "$2" ];
    then
        echo "> $1: $RESULT ✅"
    else
        echo "> $1: ❌ (expected: $2, got: $RESULT)"
    fi
}

echo "HAPPY PATH:"
test_assertion "8 9 * 9 - 9 - 9 - 4 - 1 +" 42
test_assertion "7 7 * 7 -" 42
test_assertion "1 2 * 2 / 2 * 2 4 -" 0
test_assertion "1 2 *" 2
test_assertion "4 2 /" 2
test_assertion "1 2 * 2 / 2 * 2 4 - +" 0


echo "\n"

echo "MORE THAN ONE DIGIT:"
test_assertion "12 9 * 9 - 9 - 18 - 14 - 11 +" 69
test_assertion "1000 69 +" 1069
test_assertion "500 8 *" 4000

echo "\n"

echo "ERROR STATES:"
test_assertion "(1 1 +)" "Error"
test_assertion "1 4 * 1 + 8 - 2 2 2 +" "Error"
test_assertion "1 4 * 1 + 8 - 2)" "Error"