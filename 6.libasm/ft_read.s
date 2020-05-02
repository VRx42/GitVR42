		global	ft_read
		section	.text
		extern __errno_location
ft_read:	
		mov		rax, 0
		syscall
		cmp		rax, 0
		jl		error_exit ;jl = rax < 0
		ret

error_exit:
		neg		rax
		;mov		r11, rax
		call	__errno_location	
		;mov		[r11], rax
		mov		rax, -1
		ret