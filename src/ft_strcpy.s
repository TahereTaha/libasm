
section .text
global ft_strcpy

ft_strcpy:
	xor eax, eax
	xor ecx, ecx
	strcpy_loop:
	mov al, [rdi + rcx]
	mov [rsi + rcx], al
	cmp al, 0
	je strcpy_loop_end
	inc rcx
	jmp strcpy_loop
	strcpy_loop_end:
	mov rax, rdi
	ret


