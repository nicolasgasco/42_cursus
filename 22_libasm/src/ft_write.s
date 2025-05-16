; SYNOPSIS
;        ssize_t write(int fd, const void buf[.count], size_t count);
; DESCRIPTION
;        write() writes up to count bytes from the buffer starting at buf
;        to the file referred to by the file descriptor fd.

;        The number of bytes written may be less than count if, for
;        example, there is insufficient space on the underlying physical
;        medium, or the RLIMIT_FSIZE resource limit is encountered (see
;        setrlimit(2)), or the call was interrupted by a signal handler
;        after having written less than count bytes.  (See also pipe(7).)

; RETURN VALUE
;        On success, the number of bytes written is returned.  On error,
;        -1 is returned, and errno is set to indicate the error.

;        Note that a successful write() may transfer fewer than count
;        bytes.  Such partial writes can occur for various reasons; for
;        example, because there was insufficient space on the disk device
;        to write all of the requested bytes, or because a blocked write()
;        to a socket, pipe, or similar was interrupted by a signal handler
;        after it had transferred some, but before it had transferred all
;        of the requested bytes.  In the event of a partial write, the
;        caller can make another write() call to transfer the remaining
;        bytes.  The subsequent call will either transfer further bytes or
;        may result in an error (e.g., if the disk is now full).

;        If count is zero and fd refers to a regular file, then write()
;        may return a failure status if one of the errors below is
;        detected.  If no errors are detected, or error detection is not
;        performed, 0 is returned without causing any other effect.  If
;        count is zero and fd refers to a file other than a regular file,
;        the results are not specified.

section .text

extern  __errno_location
global  ft_write

%define WRITE_SYSCALL 1

ft_write:
    mov rax, WRITE_SYSCALL ; syscall number for write
    syscall

    jc .error
    ret

.error:
    mov  rdi,   rax ; set errno
    call __errno_location WRT ..plt   ; call __errno_location WRT ..plt 
    mov  [rax], rdi ; set errno
    mov  rax,   -1  ; return -1
    ret

.end:
    mov rax, 0 ; return 0
    ret