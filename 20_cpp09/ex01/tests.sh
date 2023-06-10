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
test_assertion "1 2 3 4 5 + * - -" 26
test_assertion "7 7 * 7 -" 42
test_assertion "1 2 *" 2
test_assertion "4 2 /" 2
test_assertion "1 2 * 2 / 2 * 2 4 - +" 0
test_assertion "7 2 * 2 + 9 - 4 5 * + 3 / 1 * 5 7 + * 4 /" 27
test_assertion "1" 1
test_assertion "5 9 8 + 4 6 * + 7 - *" 170
test_assertion "2 5 * 4 + 3 2 * 1 + /" 2
test_assertion "1 2 3 4 5 + * - -" 26
test_assertion "2 4 8 + *" 24
test_assertion "1 2 3 4 5 + * - +" -24
test_assertion "7 2 * 2 + 9 - 4 5 * + 3 / 1 * 5 7 + * 4 / 2 3 4 5 6 + + * * * 8 / 3 4 + *" 2126.25
test_assertion "7 3 /" 2.33
test_assertion "-7 3 /" -2.33
test_assertion "7 2 * 2 + 9 - 4 5 * + 3 / 1 * 5 7 + * 4 / 2 3 4 5 6 + + * * * 6 / 3 4 + * 3 / 5 / 3 / 4 / 2 /" 7.88
test_assertion "7 2 * 2 + 9 - 4 5 * + 3 / 1 * 5 7 + * 4 / 2 3 4 5 6 + + * * * 6 / 3 4 + * -3 / -5 / -3 / -4 / -2 /" -7.88

echo "\n"

echo "MORE THAN ONE DIGIT:"
MORE_ONE_DIGIT_ERR="Invalid value (greather than 9)"
test_assertion "12 9 * 9 - 9 - 18 - 14 - 11 +" "$MORE_ONE_DIGIT_ERR"
test_assertion "1000 69 +" "$MORE_ONE_DIGIT_ERR"
test_assertion "500 8 *" "$MORE_ONE_DIGIT_ERR"

echo "\n"

echo "ERROR STATES:"
NOT_EMPTY_ERR="Please provide a non-empty argument"
test_assertion "" "$NOT_EMPTY_ERR"

echo "\n"
NOT_NUMERICAL_ERR="Invalid value (not numerical)"
test_assertion "(1 1 +)" "$NOT_NUMERICAL_ERR"
test_assertion "1 a +" "$NOT_NUMERICAL_ERR"
test_assertion "1 4 * 1 + 8 - 2)" "$NOT_NUMERICAL_ERR"
test_assertion "1 2 3 4 5a + * - +" "$NOT_NUMERICAL_ERR"

echo "\n"
INVALID_EXPRESSION_ERR="Invalid expression"
test_assertion "1 4 * 1 + 8 - 2 2 2 +" "$INVALID_EXPRESSION_ERR"
test_assertion "1 2 * 2 / 2 * 2 4 -" "$INVALID_EXPRESSION_ERR"
test_assertion "1 2 3 4 5 + * -" "$INVALID_EXPRESSION_ERR"
test_assertion "1 2 3 4 5 + * -" "$INVALID_EXPRESSION_ERR"
test_assertion "1 2 3 4 5 + * - - -" "$INVALID_EXPRESSION_ERR"
test_assertion "* 5 – 4 3" "$INVALID_EXPRESSION_ERR"

echo "\n"

echo "EXTRA SPACES:"
test_assertion "    7 2 * 2   + 9 -   4 5    * + 3    / 1 * 5 7    +   *   4 /" 27
test_assertion "2    4  8    + *     " 24
test_assertion "      1 2 3 4 5 + * - +       " -24