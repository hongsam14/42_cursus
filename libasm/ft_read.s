section .text
	global _ft_read

_ft_read:
	push	rbp
	mov	rbp, rsp
	mov	rax, 0x2000003
	syscall
	mov	rsp, rbp
	pop	rbp
	ret
