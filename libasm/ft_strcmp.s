section .text
	global _ft_strcmp

_ft_strcmp:
	push	rbp
	mov	rbp, rsp
	;init count index
	mov	rcx, 0
	;rdi : s1, rsi : s2
	jmp	comp

plus:
	inc	rcx

comp:
	mov	bl, byte [rdi + rcx]
	mov	bh, byte [rsi + rcx]
	cmp	bl, bh
	je	plus

done:
	sub	bl, bh
	movsx	rax, bl
	mov	rsp, rbp
	pop	rbp
	ret
