section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc
	extern ___error

_ft_strdup:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 8
	call	_ft_strlen
	push	rdi
	inc	rax
	mov	rdi, rax
	call	_malloc
	cmp	rax, 0
	jz	err
	pop	rsi
	mov	rdi, rax
	call	_ft_strcpy

done:
	mov	rsp, rbp
	pop	rbp
	ret

err:
	sub		rsp, 8
	push	rax
	call	___error
	mov		dword [rax], 12
	pop		rax
	jmp		done
