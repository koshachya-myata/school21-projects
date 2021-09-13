;int
;     strcmp(const char *s1, const char *s2);

global _ft_strcmp
section .text

_ft_strcmp:
	xor rax, rax ; = 0
	xor rdx, rdx ; = 0
	jmp while_loop

if_two_null:
	xor rax, rax
	ret

while_loop:
	mov dl, byte[rdi + rax]
	mov dh, byte[rsi + rax]
	cmp dl, dh
	jne exit
	cmp dh, 0
	je if_two_null
	inc rax
	jmp while_loop

exit:
	cmp dl, dh
	jA above
	mov rax, -1
	ret
above:
	mov rax, 1
	ret