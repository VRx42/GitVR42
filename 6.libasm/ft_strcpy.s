		global	ft_strcpy
		section	.text
ft_strcpy:
		xor	rax, rax
		xor	rcx, rcx
		cmp rsi, 0
		je return
		jmp loop

incremente:
		 inc rcx

loop:
		mov	dl, byte [rsi + rcx]
		mov	byte[rdi + rcx], dl
		cmp	dl, 0
		jnz incremente

return:
		mov	rax, rdi
		ret

