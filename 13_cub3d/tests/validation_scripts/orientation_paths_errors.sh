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
TEXTURE_PATH="./tests/textures/"

executeOrientationErrors() {
    echo "$2" > $SCRIPT_PATH$TEST_FILE
    ./cub3D "$SCRIPT_PATH$TEST_FILE" > /dev/null 2> "$SCRIPT_PATH$TEST_OUTPUT"

    # Output check
    if [ "$(cat $SCRIPT_PATH$TEST_OUTPUT)" = "$1" ]
    then
        echo "    ${GREEN}- $3 ($(cat $SCRIPT_PATH$TEST_FILE)): ok ✅${NC}"
        echo "        Message:"
        echo "            $1\n"
    else
        echo "    ${RED}- $3: not ok ❌${NC}"
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
    # $VALGRIND ./cub3D "$SCRIPT_PATH$TEST_FILE" > /dev/null 2> "$SCRIPT_PATH$VALGRIND_OUTPUT"
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

VALID_O_PATHS="EA ${TEXTURE_PATH}path_to_the_east_texture
SO ${TEXTURE_PATH}path_to_the_south_texture"

echo "\n${YELLOW}EMPTY FILE ERRORS:${NC}\n"

MAP_CONTENT="\n    \n    "
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="File with only whitespaces"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT=" "
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="File with only one space"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="\n"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="File with only one newline"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="\t"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="File with only one tab"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="                   \n"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="File ending in newline"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT=""
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="Empty file (except newline after echo)"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="\0"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="Empty file (except newline after echo)"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

echo "\n${YELLOW}ORIENTATION ERRORS${NC}:\n"

MAP_CONTENT="
${VALID_O_PATHS}
A"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="Wrong first letter (A)"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
     a\t\t"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="Wrong first letter (a) with spaces"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
0 invalid_path"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="0 as first letter"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
1 invalid_path"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="1 as first letter"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
SE"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="Wrong second letter"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
   SE   \t"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="Wrong second letter (with space)"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
NE"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="Wrong second letter"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
WO"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="Wrong second letter"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
EO valid_path"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="Wrong second letter"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
NOpath_to_file"
ERR_MESSAGE="Error: invalid identifier"
DESCRIPTION="Path without space"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
NO path_to_file"
ERR_MESSAGE="Error: file opening failed"
DESCRIPTION="Invalid path"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
NO path_to_file    \t"
ERR_MESSAGE="Error: file opening failed"
DESCRIPTION="Invalid path (with space)"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
NO path_to_file\n"
ERR_MESSAGE="Error: file opening failed"
DESCRIPTION="Invalid path (with newline)"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
NO ./fold/path_to_file"
ERR_MESSAGE="Error: file opening failed"
DESCRIPTION="Invalid path (nested)"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
NO ../../../../fold/path_to_file"
ERR_MESSAGE="Error: file opening failed"
DESCRIPTION="Invalid path (more nested)"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
${VALID_O_PATHS}
NO '\''"
ERR_MESSAGE="Error: file opening failed"
DESCRIPTION="Invalid path (\')"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
WE ${TEXTURE_PATH}path_to_the_west_texture
SO ${TEXTURE_PATH}path_to_the_south_texture
NO ${TEXTURE_PATH}path_to_the_east_texture path_to_file"
ERR_MESSAGE="Error: invalid orientation path"
DESCRIPTION="Double path"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
WE ${TEXTURE_PATH}path_to_the_west_texture
SO ${TEXTURE_PATH}path_to_the_south_texture
NO ${TEXTURE_PATH}path_to_the_east_texture path_to_file path_to_file"
ERR_MESSAGE="Error: invalid orientation path"
DESCRIPTION="Triple path"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
WE ${TEXTURE_PATH}path_to_the_west_texture
SO ${TEXTURE_PATH}path_to_the_south_texture
NO ${TEXTURE_PATH}path_to_the_east_texture F 200,200,200"
ERR_MESSAGE="Error: invalid orientation path"
DESCRIPTION="Second path is color statement"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="
WE ${TEXTURE_PATH}path_to_the_west_texture
SO ${TEXTURE_PATH}path_to_the_south_texture
NO ${TEXTURE_PATH}path_to_the_east_texture                                         path"
ERR_MESSAGE="Error: invalid orientation path"
DESCRIPTION="Second path with spaces"
executeOrientationErrors "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"