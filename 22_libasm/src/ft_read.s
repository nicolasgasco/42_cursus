; SYNOPSIS
;        ssize_t read(int fd, void buf[.count], size_t count);
; DESCRIPTION
;        read() attempts to read up to count bytes from file descriptor fd
;        into the buffer starting at buf.
; RETURN VALUE
;        On success, the number of bytes read is returned (zero indicates
;        end of file), and the file position is advanced by this number.
;        It is not an error if this number is smaller than the number of
;        bytes requested; this may happen for example because fewer bytes
;        are actually available right now (maybe because we were close to
;        end-of-file, or because we are reading from a pipe, or from a
;        terminal), or because read() was interrupted by a signal.  See
;        also NOTES.

;        On error, -1 is returned, and errno is set to indicate the error.
;        In this case, it is left unspecified whether the file position
;        (if any) changes.

section .text

extern  __errno_location

global  ft_read

%define READ_SYSCALL 0

ft_read:
    mov rax, READ_SYSCALL ; syscall number for write
    syscall

    test rax, rax         ; check if the syscall was successful
    js  .error            ; if it was not, jump to the error section

    ret

.error:
    neg  rax                         ; negate rax to get the error code

    push rbx                         ; preserve rbx
    mov  rbx, rax                    ; save the error code in rbx
    call __errno_location WRT ..plt  ; call __errno_location WRT ..plt
    mov  [rax], rbx                  ; set errno
    pop rbx                          ; restore the error code


    mov  rax,   -1  ; return -1
    ret
