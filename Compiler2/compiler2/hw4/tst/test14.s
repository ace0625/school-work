	.text
			  # _foo (i, j) 
			  # t1	%rax
			  # i	%rdi
			  # j	%rsi
	.p2align 4,0x90
	.globl_foo
_foo:
	subq $8,%rsp
			  #  t1 = i + j
	movq %rdi,%rax
	addq %rsi,%rax
			  #  return t1
	addq $8,%rsp
	ret
			  # _main () (b, i, j)
			  # b	%rbx
			  # t2	%rax
			  # t3	%rax
			  # i	%rbp
			  # j	%r12
	.p2align 4,0x90
	.globl_main
_main:
	pushq %rbx
	pushq %rbp
	pushq %r12
			  #  b = true
	movq $1,%rbx
			  #  t2 = call _foo(1, 2)
	movq $1,%rdi
	movq $2,%rsi
	call _foo
			  #  i = t2
	movq %rax,%rbp
			  #  t3 = 2 * 3
	movq $3,%r10
	movq $2,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  j = t3
	movq %rax,%r12
			  #  call _printBool(b)
	movq %rbx,%rdi
	call _printBool
			  #  call _printInt(i)
	movq %rbp,%rdi
	call _printInt
			  #  call _printInt(j)
	movq %r12,%rdi
	call _printInt
			  #  return 
	popq %r12
	popq %rbp
	popq %rbx
	ret
