; NAME
;        strlen - calculate the length of a string
; SYNOPSIS
;        size_t strlen(const char *s);
; DESCRIPTION
;        The strlen() function calculates the length of the string pointed
;        to by s, excluding the terminating null byte ('\0').
; RETURN VALUE
;        The strlen() function returns the number of bytes in the string
;        pointed to by s.

section .text
global  _ft_strlen

_ft_strlen:
    mov rbx, rdi ; get the first argument
    mov rax, 0d  ; initialize the counter
    jmp .loop    ; start the loop

.loop:
    cmp byte [rbx], 0d ; check if the current byte is \0
    je  .end           ; if it is, jump to the end
    inc rbx            ; increment the pointer
    inc rax            ; increment the counter
    jmp .loop          ; jump back to the loop

.end:
    ret