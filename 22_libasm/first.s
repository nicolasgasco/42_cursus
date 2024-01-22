extern printf
extern exit
extern test

section .data
a db 78
b dw 678 
section .text
global _start

_start:
    push rax
    mov rbx, 0

_printLoop:
    inc rax
    inc rbx
    mov cl, [rax]
