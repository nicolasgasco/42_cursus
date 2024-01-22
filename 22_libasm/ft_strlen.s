section .rodata
  msg: db "Message from inside ft_strlen", 10
  msglen: equ $ - msg

section .text

extern printf
global ft_strlen

ft_strlen:
    mov rax, 1        ; write(
    mov rdi, 1        ;   STDOUT_FILENO,
    mov rsi, msg      ;   "Hello, world!\n",
    mov rdx, msglen   ;   sizeof("Hello, world!\n")
    syscall           ; );
    mov rax, 42
    ret