section .text
	global _ft_write
	extern ___error

_ft_write:
	push	rbp
	mov	rbp, rsp
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
	pop	rbx
	mov	[rax], rbx
	mov	rax, -1
	jmp	done
