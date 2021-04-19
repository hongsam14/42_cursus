section .text
	global _ft_write

_ft_write:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 20
	mov		rax, 0x2000004
	syscall
	mov		rsp, rbp
	pop		rbp
	ret
