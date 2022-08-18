#!/bin/sh

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"
TEST_OUTPUT="test_output"
VALGRIND_OUTPUT="valgrind_output"
TEST_FILE="test_map.cub"
DEBUG_FILE="debug_output"
SCRIPT_PATH="./tests/validation_scripts/"

internetMapsValid() {
    ./cub3D $1 > /dev/null 2> "$SCRIPT_PATH$TEST_OUTPUT"

    if [ $2 = "FC" ]
    then
        CONDITION="Starting validation"
    fi
    if [ $2 = "test_W" ]
    then
        CONDITION="Starting validation"
    fi
    if [ $2 = "test_MAP" ]
    then
        CONDITION="Type ids validated successfully"
    fi

    # Output check
    if [ "$(cat $SCRIPT_PATH$DEBUG_FILE)" = "$CONDITION" ]
    then
        echo "    ${GREEN}- $1: ok ✅${NC}"
        echo "    Debug:"
        echo "        |$(cat $SCRIPT_PATH$DEBUG_FILE)|"
        echo "\n    Stderr:"
        echo "        |$(cat $SCRIPT_PATH$TEST_OUTPUT)|"
    else
        echo "    ${RED}- $1: not ok ❌${NC}"
        echo "========================================================================================="
        echo "    Debug:"
        echo "        |$(cat $SCRIPT_PATH$DEBUG_FILE)|"
        echo "\n    Stderr:"
        echo "        |$(cat $SCRIPT_PATH$TEST_OUTPUT)|"
        echo "\n    Map:"
        echo "${RED}$(cat $1)${NC}"
        echo "========================================================================================="
        echo "\n"
        exit 1
    fi

    # # Leaks check
    # $VALGRIND ./cub3D $1 > /dev/null 2> "$SCRIPT_PATH$VALGRIND_OUTPUT"
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

for file in ./tests/maps/invalid_maps/*
do
    if [ $(echo $file | grep "test_FC" | wc -l) -eq 1 ]
    then
        internetMapsValid $file "FC"
    fi
    if [ $(echo $file | grep "test_W" | wc -l) -eq 1 ]
    then
        internetMapsValid $file "test_W"
    fi
    if [ $(echo $file | grep "test_MAP" | wc -l) -eq 1 ]
    then
        internetMapsValid $file "test_MAP"
    fi
done
