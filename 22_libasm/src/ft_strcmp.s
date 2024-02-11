; SYNOPSIS
;        int strcmp(const char *s1, const char *s2);
; DESCRIPTION         top
;        The strcmp() function compares the two strings s1 and s2.  The
;        locale is not taken into account (for a locale-aware comparison,
;        see strcoll(3)).  The comparison is done using unsigned
;        characters.
; RETURN VALUE
;        The strcmp() function return an integer less than,
;        equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be
;        greater than s2.


; rdi is the first string
; rsi is the second string

global  _ft_strcmp
    
section .text

_ft_strcmp:
    mov rax, 0 ; initialize return value to 0
    jmp .loop  ; jump to the loop

.loop:
    cmp byte [rdi], 0 ; if (s1[i] == '\0')
    jne .compare      ; if s[1] is not null, compare the characters
    cmp byte [rsi], 0 ; if (s2[i] == '\0')
    je  .end          ; if s2[i] is null, return

.compare:
    mov   r8, 0          ; reset r8
    movzx r8, byte [rdi] ; r8 = s1[i]
    mov   r9, 0          ; reset r9
    movzx r9, byte [rsi] ; r9 = s2[i]
    cmp   r8, r9         ; if (s1[i] == s2[i])
    jne   .difference    ; jump to the difference if the characters are different
    inc   rsi            ; i++
    inc   rdi            ; i++
    jmp   .loop          ;  repeat the loop

.difference:
    sub r8,  r9 ; r8 = s1[i] - s2[i]
    mov rax, r8 ; return r8
    ret

.end:
    ret
