; SYNOPSIS
;        char *strdup(const char *s);

; DESCRIPTION
;        The strdup() function returns a pointer to a new string which is
;        a duplicate of the string s.  Memory for the new string is
;        obtained with malloc(3), and can be freed with free(3).

;        The strndup() function is similar, but copies at most n bytes.
;        If s is longer than n, only n bytes are copied, and a terminating
;        null byte ('\0') is added.

;        strdupa() and strndupa() are similar, but use alloca(3) to
;        allocate the buffer.
; RETURN VALUE
;        On success, the strdup() function returns a pointer to the
;        duplicated string.  It returns NULL if insufficient memory was
;        available, with errno set to indicate the error.


global  ft_strdup

extern  ft_strcpy
extern  ft_strlen
extern  malloc
extern  __errno_location

default rel

section .text

ft_strdup:
    cmp rdi, 0 ; check if the string is empty
    je  .end ; jump to the end if the string is empty

    call ft_strlen ; get the length of the string
    inc  rax        ; add 1 to the length of the string for the null byte

    push rdi      ; save the pointer to the old string
    mov  rdi, rax ; first argument is the length of the string + 1
    call malloc WRT ..plt ; allocate memory for the new string
    pop  rdi      ; restore the pointer to the old string

    cmp rax, 0 ; check if the allocation was successful
    je  .error ; jump to the error section if the allocation failed

    mov rsi, rdi ; second argument is the pointer to the old string
    mov rdi, rax ; first argument is the pointer to the new string


    call ft_strcpy ; copy the old string to the new string

    ret

.error:
    mov  rdi,   rax ; set errno
    call __errno_location WRT ..plt   ; call __errno_location WRT ..plt 
    mov  [rax], rdi ; set errno
    mov  rax,   0   ; return NULL
    ret

.end:
    mov rax, 0 ; return 0
    ret