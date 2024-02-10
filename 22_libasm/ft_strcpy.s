global  ft_strcpy
    
section .text

ft_strcpy:
    mov rbx, rax
    mov eax, 4
    mov ebx, 1
    mov ecx, [rax]
    int 0x80

