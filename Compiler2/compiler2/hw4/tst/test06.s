	.text
			  # _go () (b)
			  # t1	%rax
			  # b	%rbx
			  # t2	%rax
			  # t3	%rax
			  # t4	%rax
			  # t5	%rax
			  # t6	%rax
			  # t7	%rax
			  # t8	%rdi
			  # t9	%rax
			  # t10	%rax
			  # t11	%rax
	.p2align 4,0x90
	.globl_go
_go:
	pushq %rbx
			  #  t1 = call _malloc(8)
	movq $8,%rdi
	call _malloc
			  #  b = t1
	movq %rax,%rbx
			  #  t2 = 0 * 4
	movq $4,%r10
	movq $0,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  t3 = b + t2
	movq %rax,%r10
	movq %rbx,%rax
	addq %r10,%rax
			  #  [t3] = 3
	movq $3,%r10
	movl %r10d,(%rax)
			  #  t4 = 1 * 4
	movq $4,%r10
	movq $1,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  t5 = b + t4
	movq %rax,%r10
	movq %rbx,%rax
	addq %r10,%rax
			  #  [t5] = 4
	movq $4,%r10
	movl %r10d,(%rax)
			  #  t6 = 1 * 4
	movq $4,%r10
	movq $1,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  t7 = b + t6
	movq %rax,%r10
	movq %rbx,%rax
	addq %r10,%rax
			  #  t8 = [t7]
	movslq (%rax),%rdi
			  #  call _printInt(t8)
	call _printInt
			  #  t9 = 0 * 4
	movq $4,%r10
	movq $0,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  t10 = b + t9
	movq %rax,%r10
	movq %rbx,%rax
	addq %r10,%rax
			  #  t11 = [t10]
	movslq (%rax),%rax
			  #  return t11
	popq %rbx
	ret
			  # _main () 
			  # t12	%rdi
	.p2align 4,0x90
	.globl_main
_main:
	subq $8,%rsp
			  #  t12 = call _go()
	call _go
	movq %rax,%rdi
			  #  call _printInt(t12)
	call _printInt
			  #  return 
	addq $8,%rsp
	ret
