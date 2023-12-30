extern printf
extern exit

section .data
    msg DD "Hello, World!",0
    ftm DB "Output is: %s",10,0
section .text
global main:

main:
    PUSH msg
    PUSH ftm
    CALL printf

    PUSH 1
    CALL exit
