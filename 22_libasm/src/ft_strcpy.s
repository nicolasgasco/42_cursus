; SYNOPSIS
;        char *strcpy(char *restrict dst, const char *restrict src);

; DESCRIPTION
;        strcpy()
;               These functions copy the string pointed to by src, into a
;               string at the buffer pointed to by dst.  The programmer is
;               responsible for allocating a destination buffer large
;               enough, that is, strlen(src) + 1.  For the difference
;               between the two functions, see RETURN VALUE.

; RETURN VALUE
;        strcpy()
;               These functions return dst.

global  _ft_strcpy
    
section .text

_ft_strcpy:
    jmp .loop

    .loop:
    cmp byte [rsi], 0d    ; rsi is the source, check if the current byte is 0
    mov r8,         [rsi] ; move the current byte to r8 temporarily
    mov [rdi],      r8    ; move the current byte to the destination
    mov r8,         0     ; reset r8
    je  .end              ; if the current byte is 0, jump to the end
    inc rsi               ; move to the next byte in the source
    inc rdi               ; move to the next byte in the destination
    jmp .loop             ; repeat the loop

.end:
    ret
