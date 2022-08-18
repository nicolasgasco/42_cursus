#!/bin/sh

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

MAP_PATH="./tests/maps/color_codes/"
SCRIPT_PATH="./tests/validation_scripts/"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"
TEST_OUTPUT="test_output"
VALGRIND_OUTPUT="valgrind_output"
TEST_FILE="test_map.cub"
DEBUG_FILE="debug_output"

VALID_O_PATHS="
NO ./assets/128x128/no_texture.xpm
EA ./assets/128x128/ea_texture.xpm
WE ./assets/128x128/we_texture.xpm
SO ./assets/128x128/so_texture.xpm
"

MINIMAL_MAP="
1111
10W1
1111
"

executeFloorCeilingTest() {
    echo "$2" > $SCRIPT_PATH$TEST_FILE
    ./cub3D "$SCRIPT_PATH$TEST_FILE" > /dev/null 2> "$SCRIPT_PATH$TEST_OUTPUT" &
    sleep 1
    kill -9 $!

    # Output check
    if [ "$(grep "$1" $SCRIPT_PATH$DEBUG_FILE | wc -l)" -eq 1 ]
    then
        echo "    ${GREEN}- Floor/Ceiling colors (${NC}$3${GREEN}): ok ✅${NC}"
        echo "        Message:"
        echo "            $1\n"
    else
        echo "    ${RED}- Floor/Ceiling colors ($3): not ok ❌${NC}"
        echo "========================================================================================="
        echo "    Expected:"
        echo "        |$1|\n"
        echo "    Got:"
        echo "        |$(cat $SCRIPT_PATH$DEBUG_FILE)|"
        echo "========================================================================================="
        echo "\n"
        exit 1
    fi

    # # Leaks check
    # $VALGRIND ./cub3D "$SCRIPT_PATH$TEST_FILE" > /dev/null 2> "$SCRIPT_PATH$VALGRIND_OUTPUT"
    # VALGRIND_ERRORS=$(cat $SCRIPT_PATH$VALGRIND_OUTPUT | grep "definitely lost: 0 bytes in 0 blocks" | wc -l)
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
    #     # echo "\n$(less $SCRIPT_PATH$VALGRIND_OUTPUT)"
    #     exit 1
    # fi
    # echo "=========================================================================================================="
}

echo "\n${YELLOW}Floor color validation:${NC}\n"

TEST_STATEMENT="F 0,0,0"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
C 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Floor color is 0"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="F 10,10,10"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
C 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Floor color is 657930"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="F 250,0,0"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
C 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Floor color is 16384000"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="F 0,255,0"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
C 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Floor color is 65280"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="F 0,0,255"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
C 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Floor color is 255"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="F 255,255,255"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
C 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Floor color is 16777215"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

echo "\n${YELLOW}Ceiling color validation:${NC}\n"

TEST_STATEMENT="C 0,0,0"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
F 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Ceiling color is 0"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="C 10,10,10"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
F 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Ceiling color is 657930"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="C 250,0,0"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
F 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Ceiling color is 16384000"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="C 0,255,0"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
F 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Ceiling color is 65280"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="C 0,0,255"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
F 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Ceiling color is 255"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"

TEST_STATEMENT="C 255,255,255"
MAP_CONTENT="${VALID_O_PATHS}
${TEST_STATEMENT}
F 225,30,0
${MINIMAL_MAP}"
DEBUG_MSG="Ceiling color is 16777215"
executeFloorCeilingTest "$DEBUG_MSG" "$MAP_CONTENT" "$TEST_STATEMENT"