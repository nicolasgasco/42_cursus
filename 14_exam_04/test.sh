#!/bin/bash

test_line () {
	./test $@ &> test_files/out.res
	sleep .250
	./microshell $@ &> test_files/microshell.res
	sleep .250
	cmp --silent test_files/microshell.res test_files/out.res || (diff test_files/out.res test_files/microshell.res ; exit 1)
	# lsof -c microshell | grep -v cwd | grep -v txt | grep -v 0r | grep -v 1w | grep -v 2u | grep microshel
	printf "\e[1;32m[OK]\e[0m"
}

printf "\e[1;32mCompile\n"
gcc -g -Wall -Werror -Wextra microshell.c -o microshell
gcc -g -Wall -Werror -Wextra ./test_files/test.c -o test
printf "\e[1;36mTest\n\e[0m"
rm -f out.res leaks.res out
echo "\nCd errors:"
test_line cd
test_line cd ciao miao ";"
test_line cd ciao
echo "\nSimple commands:"
test_line /bin/ls
test_line /bin/cat microshell.c
test_line /bin/ls microshell.c
test_line /bin/ls salut
echo "\nSemi-colons:"
test_line ";"
test_line ";" ";"
test_line ";" ";" /bin/echo OK
test_line ";" ";" /bin/echo OK ";"
test_line ";" ";" /bin/echo OK ";" ";"
test_line ";" ";" /bin/echo OK ";" ";" ";" /bin/echo OK
echo "\nPipes"
test_line /bin/ls "|" /usr/bin/grep microshell
test_line /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro
test_line /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro
test_line /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell
test_line /bin/ls ewqew "|" /usr/bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo
test_line /bin/ls "|" /usr/bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo ftest ";"
test_line /bin/echo ftest ";" /bin/echo ftewerwerwerst ";" /bin/echo werwerwer ";" /bin/echo qweqweqweqew ";" /bin/echo qwewqeqrtregrfyukui ";"
test_line /bin/ls ftest ";" /bin/ls ";" /bin/ls werwer ";" /bin/ls microshell.c ";" /bin/ls subject.en.txt ";"
test_line /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";"
test_line /bin/cat subject.en.txt "|" /usr/bin/grep a "|" /usr/bin/grep b ";" /bin/cat subject.en.txt ";"
test_line /bin/cat subject.en.txt "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat subject.en.txt ";"
test_line /bin/cat subject.en.txt "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat subject.en.txt
test_line /bin/cat subject.en.txt ";" /bin/cat subject.en.txt "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat subject.en.txt
test_line ";" /bin/cat subject.en.txt ";" /bin/cat subject.en.txt "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat subject.en.txt
test_line blah "|" /bin/echo OK
test_line blah "|" /bin/echo OK ";"
printf "\n"
printf "\e[1;32mDone\e[0m\n"
rm -rf microshell.dSYM leaks.res