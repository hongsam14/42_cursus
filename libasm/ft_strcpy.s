section .text
	global _ft_strcpy

_ft_strcpy:
	push	rbp
	mov		rbp, rsp
	mov		rdx, 0
	lea		s1, rsp
	jz		end
	mov		rax, s1
	mov		s2, qword [rsp + 8]
	jnz		cpy

end:
	mov		rsp, rbp
	pop		rbp
	ret

plus:
	inc		rdx

cpy:
	mov rcx, byte [rbx + rdx]
	jz		end
	mov	byte [rax + rdx], rcx
	jmp		plus

section .bss
	s1 resq 1
	s2 resq 2
