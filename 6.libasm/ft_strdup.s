		global ft_strdup
		section .text
		extern	ft_strlen
		extern	malloc
		extern	ft_strcpy
		
ft_strdup:
		cmp	rdi, 0
		je	fail_exit
		call	ft_strlen
		inc	rax
		push	rdi
		mov	rdi, rax
		call	malloc
		cmp rax, 0
		je fail_exit
		pop	rdi
		push rsi
		mov	rsi, rdi
		mov	rdi, rax	
		call	ft_strcpy
		pop rsi
		ret

fail_exit:	
		mov	rax, 0
		ret
