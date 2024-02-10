global  _ft_strcpy
    
section .text

; rdi is first argument dest
; rsi is second argument src

_ft_strcpy:
    jmp .loop

    .loop:
    cmp byte [rsi], 0d ; check if the current byte is \0
    mov r8, [rsi]      ; move the current byte to r8
    mov [rdi], r8      ; move the current byte to the destination
    mov r8, 0         ; move 0 to r8
    je  .end           ; if it is, jump to the end
    inc rsi            ; move to the next byte
    inc rdi            ; move to the next byte
    jmp .loop          ; jump back to the loop

.end:
    ret
