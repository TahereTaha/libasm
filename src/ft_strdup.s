
section .text
global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:
	push rbx
	mov rbx, rdi
	call ft_strlen
	mov rdi, rax
	call malloc wrt ..plt
	cmp rax, 0
	je return
	mov rdi, rax
	mov rsi, rbx
	call ft_strcpy
return:
	pop rbx
	ret

