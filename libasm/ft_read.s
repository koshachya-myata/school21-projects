; ssize_t
;     read(int fildes, void *buf, size_t nbyte);

global	_ft_read
extern ___error
section	.text

_ft_read:	; fd = rdi, buffer = rsi, bytes = rdx
			mov		rax, 0x2000003
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
