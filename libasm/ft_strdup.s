
;char *
;     strdup(const char *s1);

global _ft_strdup
section .text
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
	xor rax, rax
	cmp rdi, 0 ; s1 == NULL?
	je error
	xor rsi, rsi
	xor r8, r8
	push rdi
	call _ft_strlen ;  rdi = s1 -> rax = len
	inc rax
	mov rdi, rax
	call _malloc ; rdi = len -> rax = alloc_mem
	cmp rax, 0
	je error
	mov rdi, rax ; rdi = alloc_mem
	pop rsi
	call _ft_strcpy ; rdi = alloc_mem, rsi = s1 -> rax = copy s1
	ret 

error:
	ret