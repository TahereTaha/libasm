
section .text
global ft_write

ft_write:
	mov eax, 0x1
	syscall
	ret

