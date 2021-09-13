; ssize_t
;     write(int fildes, const void *buf, size_t nbyte);

global	_ft_write
extern ___error
section	.text

_ft_write:	; fd = rdi, buffer = rsi, bytes = rdx rax = system call num
			mov		rax, 0x2000004
			syscall
			jc error
			ret

error: 
			mov r8, rax  ; save error code
			push -1 ; initial stack
			call ___error ; rax <- errno
			mov qword[rax], r8 ; errno <- code error
			pop rax
			ret
