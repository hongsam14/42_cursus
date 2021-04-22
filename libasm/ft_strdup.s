section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	push	rbp
	mov	rbp, rsp
	call	_ft_strlen
	push	rdi
	inc	rax
	mov	rdi, rax
	call	_malloc
	;cmp	rax, 0
	;jz	done
	pop	rsi
	mov	rdi, rax
	call	_ft_strcpy

done:
	mov	rsp, rbp
	pop	rbp
	ret
