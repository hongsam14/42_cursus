section .text
	global _ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 8
	mov		rax, 0
	jmp		comp

comp:
	cmp		BYTE[rdi + rax], 0
	jne		plus
	jmp		done

plus:
	inc		rax
	jmp		comp

done:
	mov		rsp, rbp
	pop		rbp
	ret
