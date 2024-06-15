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
global  ft_strlen

ft_strlen:
    mov rbx, rdi ; move argument to rbx
    mov rax, 0d  ; set counter and return value to 0

    cmp rdi, 0d  ; check if the string is empty (this check is an extra protection, it should not be necessary)
    je  .end     ; if it is, jump to the end

    jmp .loop    ; jump to the loop

.loop:
    cmp byte [rbx + rax], 0d ; check if the current character is the null byte
    je  .end                 ; if it is, jump to the end
    inc rax                  ; increment the counter and return value
    jmp .loop                ; jump back to the loop

.end:
    ret
