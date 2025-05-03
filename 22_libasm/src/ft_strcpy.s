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

global  ft_strcpy
    
section .text

ft_strcpy:
    cmp rsi, 0   ; if the first byte in src is 0,
    je  .end     ; jump to the end

    cmp rdi, 0   ; if the first byte in dst is 0,
    je  .end     ; jump to the end

    mov rax, rdi ; move the address of dst to rax (return value)

    mov rcx, 0   ; set counter to 0
    jmp .loop

.loop:
    xor r8, r8           ; clear r8 (r8 is used to store the current byte of src)
    mov r8b, [rsi + rcx] ; load the current byte of src into r8b
    mov [rdi + rcx], r8b ; copy the current byte to the destination

    inc rcx              ; increment the counter

    cmp r8b, 0           ; if the current byte is 0, jump to the end
    jne .loop            ; if the current byte is not 0, repeat the loop

    ret

.end:
    mov rax, 0 ; return 0
    ret
