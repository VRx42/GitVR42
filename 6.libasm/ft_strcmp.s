		global	ft_strcmp
		section	.text

ft_strcmp:
		push rdi
		push rsi

loop:
		mov	al, byte[rdi]
		cmp	al, byte[rsi]
		jne	not_equal
		cmp	byte[rdi], 0
		je	equal
		inc	rdi 
		inc	rsi
		jmp	loop

not_equal:
		mov	al, byte[rdi]
		sub	al, byte[rsi]
		cmp al, 0
		jl 	inferior
		mov rax, 1
		jmp end

inferior:
		mov rax, -1
		jmp end

equal:
		mov	rax, 0
		jmp end

end:
		pop rsi
		pop rdi
		ret
 