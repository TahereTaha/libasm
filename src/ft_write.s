
section .text
global ft_write
extern __errno_location

ft_write:
	mov rax, 0x1
	syscall
	cmp rax, 0
	jge return
	mov rbx, rax
	call __errno_location wrt ..plt
	neg rbx
	mov [rax], rbx
	mov rax, -1
return:
	ret

