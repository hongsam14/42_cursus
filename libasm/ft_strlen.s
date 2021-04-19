section .text
	global _ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp, rsp
	mov		rax, 0
	jmp		comp

plus:
	inc		rax

comp:
	cmp		byte [rdi + rax], 0
	jne		plus

done:
	mov		rsp, rbp
	pop		rbp
	ret
