		global	ft_write
		section	.text
		extern __errno_location
ft_write:	
		mov		rax, 1
		syscall
		cmp		rax, 0
		jl		error_exit
		ret

error_exit:
		neg		rax;
		call	__errno_location
		mov		rax, -1
		ret