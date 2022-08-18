#!/bin/sh

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

SCRIPT_PATH="./tests/validation_scripts/"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"
TEST_OUTPUT="test_output"
VALGRIND_OUTPUT="valgrind_output"
TEST_FILE="test_map.cub"

executeFileErrorTest() {
    ./cub3D $3 $4 $5 > /dev/null 2> "$SCRIPT_PATH$TEST_OUTPUT"

    # Output check
    if [ "$(cat $SCRIPT_PATH$TEST_OUTPUT)" = "$1" ]
    then
        echo "    ${GREEN}- $2: ok ✅${NC}"
        echo "        Message:"
        echo "            $1\n"
    else
        echo "    ${RED}- $2: not ok ❌${NC}"
        echo "========================================================================================="
        echo "    Expected:"
        echo "        |$1|\n"
        echo "    Got:"
        echo "        |$(cat $SCRIPT_PATH$TEST_OUTPUT)|"
        echo "========================================================================================="
        echo "\n"
        exit 1
    fi

    # # Leaks check
    # $VALGRIND ./cub3D > /dev/null 2> "$SCRIPT_PATH$VALGRIND_OUTPUT"
    # VALGRIND_ERRORS=$(cat $SCRIPT_PATH$VALGRIND_OUTPUT | grep "in use at exit: 0 bytes in 0 blocks" | wc -l)
    # if [ $VALGRIND_ERRORS -eq  1 ]
    # then
    #     echo "        ${GREEN}No memory leaks detected 👍${NC}"
    # else
    #     echo "        ${RED}Memory leaks detected ⛔${NC}"
    #     echo "\n$(less $SCRIPT_PATH$VALGRIND_OUTPUT)"
    #     exit 1
    # fi
    
    # # Errors check
    # VALGRIND_ERRORS=$(cat $SCRIPT_PATH$VALGRIND_OUTPUT | grep "ERROR SUMMARY: 0 errors from 0 contexts" | wc -l)
    # if [ $VALGRIND_ERRORS -eq  1 ]
    # then
    #     echo "        ${GREEN}No Valgrind errors found 👍${NC}"
    # else
    #     echo "        ${RED}Valgrind errors found ⛔${NC}"
    #     echo "\n$(less $SCRIPT_PATH$VALGRIND_OUTPUT)"
    #     exit 1
    # fi
    # echo "=========================================================================================================="
}

echo "\n${YELLOW}EMPTY FILE ERROR:${NC}\n"
touch "${SCRIPT_PATH}empty_file.cub"
DESC="Empty file but existing"
ERR_MESSAGE="Error: empty scene file"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "tests/validation_scripts/empty_file.cub"

echo "\n${YELLOW}ARGUMENTS ERRORS:${NC}\n"

DESC="No arguments"
ERR_MESSAGE="Error: arguments"
executeFileErrorTest "$ERR_MESSAGE" "$DESC"

DESC="Two arguments"
ERR_MESSAGE="Error: arguments"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1" "arg2"

DESC="Three arguments"
ERR_MESSAGE="Error: arguments"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1" "arg2" "arg3"

DESC="One argument, invalid file"
ERR_MESSAGE="Error: file opening failed"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1.cub"

echo "\n${YELLOW}EXTENSION ERRORS:${NC}\n"

DESC="One argument no extension (arg1)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1"

DESC="One argument with dot (arg1.)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1."

DESC="One argument wrong extension (arg1.txt)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1.txt"

DESC="One argument wrong extension (arg1.cubb)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1.cubb"

DESC="One argument wrong extension (arg1.cu)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1.cu"

DESC="One argument extension without dot (arg1cub)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "arg1cub"

DESC="One argument extension without dot (cubcub)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "cubcub"

DESC="One argument no filename (.cub)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" ".cub"

DESC="One argument dot (.)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" ".cub"

DESC="One argument only newline (\n)"
ERR_MESSAGE="Error: invalid extension"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" "\n"

DESC="One argument only space ( )"
ERR_MESSAGE="Error: arguments"
executeFileErrorTest "$ERR_MESSAGE" "$DESC" " "
