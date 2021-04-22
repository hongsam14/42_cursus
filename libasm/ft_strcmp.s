section .text
	global _ft_strcmp

_ft_strcmp:
	push	rbp
	mov	rbp, rsp
	;init count index, return rax
	mov	rcx, 0
	;rdi : s1, rsi : s2
	jmp	comp

plus:
	cmp	rax, 0
	jz	done
	inc	rcx

comp:
	movzx	rax, byte [rdi + rcx]
	movzx	rbx, byte [rsi + rcx]
	cmp	rax, rbx
	je	plus

done:
	sub	rax, rbx
	mov	rsp, rbp
	pop	rbp
	ret
