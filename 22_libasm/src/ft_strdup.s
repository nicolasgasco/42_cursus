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

global  _ft_strdup
extern  _ft_strlen
    
; first argument is in rdi

section .text

_ft_strdup:
    mov r8, rdi ; save the pointer to the string
    call _ft_strlen ; get the length of the string

    mov rdi, rax ; first argument is the length of the string
    ret