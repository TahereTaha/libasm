
section .text
global ft_strcmp

ft_strcmp:
	xor eax, eax
	xor ecx, ecx
	strcmp_loop:
	mov al, [rsi + rcx]
	mov ah, [rdi + rcx]
	cmp al, ah
	jne strcmp_loop_end
	cmp al, 0
	je strcmp_loop_end
	inc rcx
	jmp strcmp_loop
	strcmp_loop_end:
	movsx esi, al
	movsx edi, ah
	mov eax, esi
	sub eax, edi
	ret

