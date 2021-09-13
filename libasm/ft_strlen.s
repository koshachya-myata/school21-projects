
;size_t ft_strlen(const char *str)

global _ft_strlen
section .text

_ft_strlen:
	xor rax, rax ; rax = 0
	jmp while_loop

while_loop:
	cmp byte[rdi + rax] , 0
	je exit
	inc rax
	jmp while_loop

exit:
	ret