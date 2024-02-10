global  _ft_strcpy
    
section .text

_ft_strcpy:
    mov rbx, rax
    mov eax, 4
    mov ebx, 1
    mov ecx, [rax]
    int 0x80

