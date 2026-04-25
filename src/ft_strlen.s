
section .text
global ft_strlen

ft_strlen:
	xor eax, eax
	strlen_loop:
	mov sil, [rdi + rax]
	cmp sil, 0
	je strlen_loop_end
	inc rax
	jmp strlen_loop
	strlen_loop_end:
	ret
