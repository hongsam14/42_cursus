section .text
	global _ft_write
	extern ___error

_ft_write:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 8
	mov	rax, 0x2000004
	syscall
	jc	err
	
done:
	mov	rsp, rbp
	pop	rbp
	ret

err:
	push	rax
	call	___error
	pop	rdx
	mov	[rax], rdx
	mov	rax, -1
	jmp	done
