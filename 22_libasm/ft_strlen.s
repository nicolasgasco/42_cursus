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