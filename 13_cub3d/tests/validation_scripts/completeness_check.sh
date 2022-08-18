#!/bin/sh

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

MAP_PATH="./tests/maps/color_codes/"
SCRIPT_PATH="./tests/validation_scripts/"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"
TEST_OUTPUT="test_output"
VALGRIND_OUTPUT="valgrind_output"
TEST_FILE="test_map.cub"
TEXTURE_PATH="./tests/textures/"

executeErrorTest() {
    echo "$2" > $SCRIPT_PATH$TEST_FILE
    ./cub3D "$SCRIPT_PATH$TEST_FILE" > /dev/null 2> "$SCRIPT_PATH$TEST_OUTPUT"

    # Output check
    if [ "$(cat $SCRIPT_PATH$TEST_OUTPUT)" = "$1" ]
    then
        echo "    ${GREEN}- $3 (${NC}$(cat $SCRIPT_PATH$TEST_FILE)${GREEN}): ok ✅${NC}"
        echo "        Message:"
        echo "            $1\n"
    else
        echo "    ${RED}- $3 (${NC}$(cat $SCRIPT_PATH$TEST_FILE)${RED}): not ok ❌${NC}"
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

echo "\nCOLORS COMPLETENESS CHECKS:"

MAP_CONTENT="F 255,20,20"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="C is missing"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="F 255,20,20"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="F is missing"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_west_texture
            EA ${TEXTURE_PATH}path_to_the_east_texture
            F 255,20,20"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="All orientations, C is missing"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_west_texture
            EA ${TEXTURE_PATH}path_to_the_east_texture
            C 255,20,20"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="All orientations, F is missing"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="F 255,20,20
             C 255,20,20"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="C is equal F"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="F 255,20,20
             C 255,20,20,"
ERR_MESSAGE="Error: invalid color statement"
DESCRIPTION="C is equal F (except for comma after C)"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="F 255,20,20,
             C 255,20,20"
ERR_MESSAGE="Error: invalid color statement"
DESCRIPTION="C is equal F (except for comma after F)"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="C 0,0,0
             F 0,0,0"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="F is equal C"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_west_texture
            EA ${TEXTURE_PATH}path_to_the_east_texture
            C 255,20,20
            F 255,20,20"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="All orientations, F is equal C"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

echo "\nORIENTATION PATHS COMPLETENESS CHECKS:"

MAP_CONTENT="SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_west_texture
            EA ${TEXTURE_PATH}path_to_the_east_texture
            C 20,20,20
            F 255,20,20"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="NO is missing"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_west_texture
            EA ${TEXTURE_PATH}path_to_the_east_texture
            C 20,20,20
            F 255,20,20"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="SO is missing"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_south_texture
            SO ${TEXTURE_PATH}path_to_the_west_texture
            EA ${TEXTURE_PATH}path_to_the_east_texture
            C 20,20,20
            F 255,20,20"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="WE is missing"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_south_texture
            SO ${TEXTURE_PATH}path_to_the_west_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            C 20,20,20
            F 255,20,20"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="EA is missing"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_south_texture"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="All missing except NO"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="SO ${TEXTURE_PATH}path_to_the_south_texture"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="All missing except SO"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="WE ${TEXTURE_PATH}path_to_the_south_texture"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="All missing except WE"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="EA ${TEXTURE_PATH}path_to_the_south_texture"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="All missing except EA"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_west_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Duplicate path_to_the_west_texture"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_south_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Duplicate path_to_the_south_texture"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_north_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Duplicate path_to_the_north_texture"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_east_texture
            SO ${TEXTURE_PATH}path_to_the_east_texture
            WE ${TEXTURE_PATH}path_to_the_north_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Duplicate path_to_the_east_texture"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"


MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_east_texture
            SO ${TEXTURE_PATH}path_to_the_east_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Triplicated path_to_the_east_texture"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="C 255,20,20
            C 10,10,10"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="C is duplicated"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="C 10,10,10
            C 10,10,10"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="C is duplicated (+ same value)"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="F 10,20,30
            C 255,20,20
            C 10,10,10"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="F correct, C is duplicated"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="F 10,20,30
            C 10,10,10
            C 10,10,10"
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="F correct, C is duplicated (+ same value)"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_west_texture
            EA ${TEXTURE_PATH}path_to_the_east_texture
            1 ${TEXTURE_PATH}path_to_the_invalid_texture
            F 0,0,0
            C 0,10,0"
ERR_MESSAGE="Error: incomplete scene info"
DESCRIPTION="1 as first letter, otherwise all OK"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

echo "\nDUPLICATION CHECKS:"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0
            
            NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0
            "
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Double type ids descriptions"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0
            
            NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0

            NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0
            "
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Triple type ids descriptions"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0
            NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0
            "
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Triple type ids descriptions (no nl)"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"

MAP_CONTENT="NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture


            
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0






            NO ${TEXTURE_PATH}path_to_the_north_texture
            SO ${TEXTURE_PATH}path_to_the_south_texture
            WE ${TEXTURE_PATH}path_to_the_east_texture
            EA ${TEXTURE_PATH}path_to_the_west_texture
            F 0,0,0
            C 0,10,0
            "
ERR_MESSAGE="Error: duplicated scene info"
DESCRIPTION="Triple type ids descriptions (many \n)"
executeErrorTest "$ERR_MESSAGE" "$MAP_CONTENT" "$DESCRIPTION"