section .text

global start

start:
    MOV al,2
    MOV bl,2
    MUL bl

    MOV ebx,1
    INT 80h