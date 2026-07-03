
section .text
global ft_read
extern __errno_location

ft_read:
	mov rax, 0x0
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

