	.text
			  # _main () (b, i, j)
			  # b	%rdi
			  # i	%rbx
			  # j	%rbp
	.p2align 4,0x90
	.globl_main
_main:
	pushq %rbx
	pushq %rbp
	subq $8,%rsp
			  #  b = true
	movq $1,%rdi
			  #  i = 2
	movq $2,%rbx
			  #  j = 6
	movq $6,%rbp
			  #  call _printBool(b)
	call _printBool
			  #  call _printInt(i)
	movq %rbx,%rdi
	call _printInt
			  #  call _printInt(j)
	movq %rbp,%rdi
	call _printInt
			  #  return 
	addq $8,%rsp
	popq %rbp
	popq %rbx
	ret
