make re

BLUE='\033[0;36m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

executeTest() {
    echo "${BLUE}$2 ARG IS $1:\n${NC}"
    ./00 $1
    echo "${BLUE}\n--------------------------------\n${NC}"
}

# CHAR
executeTest "a" "CHAR"
executeTest "z" "CHAR"
executeTest "?" "CHAR"
executeTest "." "CHAR"

echo "${GREEN}\n================================\n${NC}"

# INT
executeTest "0" "INT"
executeTest "-42" "INT"
executeTest "+42" "INT"
executeTest "10" "INT"
executeTest "2147483647" "INT"
executeTest "-2147483648" "INT"

echo "${GREEN}\n================================\n${NC}"

# FLOAT
executeTest "0.0f" "FLOAT"
executeTest "-4.2f" "FLOAT"
executeTest "+4.2f" "FLOAT"
executeTest "+42.0f" "FLOAT"
executeTest "-inff" "FLOAT"
executeTest "+inff" "FLOAT"
executeTest "nanf" "FLOAT"
executeTest "1.175494351E-38f" "FLOAT"
executeTest "3.402823466E+38f" "FLOAT"

echo "${GREEN}\n================================\n${NC}"

# DOUBLE
executeTest "0.0" "DOUBLE"
executeTest "-4.2" "DOUBLE"
executeTest "+4.2" "DOUBLE"
executeTest "+42.0" "DOUBLE"
executeTest "-inf" "DOUBLE"
executeTest "+inf" "DOUBLE"
executeTest "nan" "DOUBLE"
executeTest "-1.7976931348623157E+308" "DOUBLE"
executeTest "1.7976931348623157E+308" "DOUBLE"