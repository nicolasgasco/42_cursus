#!/bin/bash

make re

test_assertion()
{
    RESULT=$(./RPN "$1" 2>&1)
    if [ $# -eq 0 ]
    then
        RESULT=$(./RPN 2>&1)
    else
        RESULT=$(./RPN "$1" 2>&1)
    fi
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
test_assertion "1 2 *" 2
test_assertion "4 2 /" 2
test_assertion "1 2 * 2 / 2 * 2 4 - +" 0
test_assertion "7 2 * 2 + 9 - 4 5 * + 3 / 1 * 5 7 + * 4 /" 27
test_assertion "1" 1
test_assertion "5 9 8 + 4 6 * + 7 - *" 170

echo "\n"

echo "MORE THAN ONE DIGIT:"
test_assertion "12 9 * 9 - 9 - 18 - 14 - 11 +" 69
test_assertion "1000 69 +" 1069
test_assertion "500 8 *" 4000

echo "\n"

echo "ERROR STATES:"
test_assertion "" "Error"
test_assertion "(1 1 +)" "Error"
test_assertion "1 4 * 1 + 8 - 2 2 2 +" "Error"
test_assertion "1 4 * 1 + 8 - 2)" "Error"
test_assertion "1 2 * 2 / 2 * 2 4 -" "Error"
