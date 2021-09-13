
;char *
;     strcpy(char * dst, const char * src);
; copy src to dst including \0
; return dst

global _ft_strcpy
section .text

_ft_strcpy:
	xor rax, rax ; rax = 0
	xor rdx, rdx
	jmp while_loop

while_loop:
	cmp byte[rsi + rax], 0
	je exit
	mov dh, byte[rsi + rax]
	mov byte[rdi + rax], dh
	inc rax
	jmp while_loop

exit:
	mov dh, 0
	mov byte[rdi + rax], dh
	mov rax, rdi
	ret