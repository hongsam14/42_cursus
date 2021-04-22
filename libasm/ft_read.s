section .text
	global _ft_read
	extern ___error

_ft_read:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 8
	mov	rax, 0x2000003
	syscall
	jc	err

done:
	mov	rsp, rbp
	pop	rbp
	ret

err:
	push	rax
	call	___error
	pop	rbx
	mov	[rax], rbx
	mov	rax, -1
	jmp	done
