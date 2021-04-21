section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	push	rbp
	mov	rbp, rsp
	;ft_strlen
	;s1 : rdi
	call	_ft_strlen
	push	rdi
	;malloc
	;ft_strlen->rax
	inc	rax
	mov	rdi, rax
	call	_malloc
	;malloc fail check
	cmp	rax, 0
	jz	done
	;rdx = s1
	pop	rdx
	;init count index
	mov	rcx, 0
	jmp	dup

plus:
	inc	rcx

dup:
	mov	bl, byte [rdx + rcx]
	mov	byte [rax + rcx], bl
	cmp	bl, 0
	jnz	plus

done:
	mov	rsp, rbp
	pop	rbp
	ret
