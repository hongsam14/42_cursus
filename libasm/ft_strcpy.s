section .text
	global _ft_strcpy

_ft_strcpy:
	push	rbp
	mov	rbp, rsp
	;init rcx (count index) 0
	;mov	rcx, 0
	xor		rcx, rcx
	;rdi : dest, rsi : src
	;src null check
	cmp	rsi, 0
	jz	done
	jmp	cpy

plus:
	inc	rcx

cpy:
	mov	dl, byte[rsi + rcx]
	mov	byte [rdi + rcx], dl
	cmp	dl, 0
	jnz	plus

done:
	mov		rax, rdi
	mov		rsp, rbp
	pop		rbp
	ret
