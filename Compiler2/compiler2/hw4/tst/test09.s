	.text
			  # _go () (b, i, a)
			  # t1	%rax
			  # t2	%rax
			  # t3	%rax
			  # t4	%rax
			  # t5	%rcx
			  # t6	%rdx
			  # t7	%rdx
			  # t8	%rsi
			  # t9	%rsi
			  # t10	%rsi
			  # t11	%rsi
			  # t12	%rcx
			  # t13	%rax
			  # t14	%r13
			  # t15	%rax
			  # t16	%rax
			  # t17	%rcx
			  # t18	%rcx
			  # t19	%rcx
			  # t20	%rax
			  # t21	%rax
			  # t22	%rcx
			  # t23	%rax
			  # a	%rbp
			  # b	%r12
			  # i	%rbx
	.p2align 4,0x90
	.globl_go
_go:
	pushq %rbx
	pushq %rbp
	pushq %r12
	pushq %r13
	subq $8,%rsp
			  #  i = 0
	movq $0,%rbx
			  #  t1 = call _malloc(16)
	movq $16,%rdi
	call _malloc
			  #  a = t1
	movq %rax,%rbp
			  #  t2 = 1 * 4
	movq $4,%r10
	movq $1,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  t3 = a + t2
	movq %rax,%r10
	movq %rbp,%rax
	addq %r10,%rax
			  #  [t3] = 2
	movq $2,%r10
	movl %r10d,(%rax)
			  #  t4 = true
	movq $1,%rax
			  #  t5 = true
	movq $1,%rcx
			  #  t6 = 1 < 2
	movq $2,%r10
	movq $1,%r11
	cmpq %r10,%r11
	setl %dl
	movzbq %dl,%rdx
			  #  if t6 == true goto L1
	movq $1,%r11
	cmpq %r11,%rdx
	je go_L1
			  #  t7 = false
	movq $0,%rdx
			  #  t8 = 3 > 4
	movq $4,%r10
	movq $3,%r11
	cmpq %r10,%r11
	setg %sil
	movzbq %sil,%rsi
			  #  if t8 == false goto L2
	movq $0,%r11
	cmpq %r11,%rsi
	je go_L2
			  #  t9 = 7 * 8
	movq $8,%r10
	movq $7,%r11
	movq %r11,%rsi
	imulq %r10,%rsi
			  #  t10 = 6 + t9
	movq $6,%r11
	movq %rsi,%r10
	movq %r11,%rsi
	addq %r10,%rsi
			  #  t11 = 5 == t10
	movq $5,%r11
	cmpq %rsi,%r11
	sete %sil
	movzbq %sil,%rsi
			  #  if t11 == false goto L2
	movq $0,%r11
	cmpq %r11,%rsi
	je go_L2
			  #  t7 = true
	movq $1,%rdx
			  # L2:
go_L2:
			  #  if t7 == true goto L1
	movq $1,%r11
	cmpq %r11,%rdx
	je go_L1
			  #  t5 = false
	movq $0,%rcx
			  # L1:
go_L1:
			  #  if t5 == true goto L0
	movq $1,%r11
	cmpq %r11,%rcx
	je go_L0
			  #  t12 = !true
	movq $1,%r10
	movq %r10,%rcx
	notq %rcx
			  #  if t12 == true goto L0
	movq $1,%r11
	cmpq %r11,%rcx
	je go_L0
			  #  t4 = false
	movq $0,%rax
			  # L0:
go_L0:
			  #  b = t4
	movq %rax,%r12
			  #  t13 = -3
	movq $3,%r10
	movq %r10,%rax
	negq %rax
			  #  t14 = -t13
	movq %rax,%r13
	negq %r13
			  #  t15 = 5 * 4
	movq $4,%r10
	movq $5,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  t16 = t15 / 2
	movq $2,%r10
	cqto
	idivq %r10
			  #  t17 = 1 * 4
	movq $4,%r10
	movq $1,%r11
	movq %r11,%rcx
	imulq %r10,%rcx
			  #  t18 = a + t17
	movq %rcx,%r10
	movq %rbp,%rcx
	addq %r10,%rcx
			  #  t19 = [t18]
	movslq (%rcx),%rcx
			  #  t20 = t16 * t19
	imulq %rcx,%rax
			  #  t21 = t14 + t20
	movq %rax,%r10
	movq %r13,%rax
	addq %r10,%rax
			  #  t22 = i * 2
	movq $2,%r10
	movq %rbx,%rcx
	imulq %r10,%rcx
			  #  t23 = t21 + t22
	addq %rcx,%rax
			  #  i = t23
	movq %rax,%rbx
			  #  call _printBool(b)
	movq %r12,%rdi
	call _printBool
			  #  return i
	movq %rbx,%rax
	addq $8,%rsp
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	ret
			  # _main () 
			  # t24	%rdi
	.p2align 4,0x90
	.globl_main
_main:
	subq $8,%rsp
			  #  t24 = call _go()
	call _go
	movq %rax,%rdi
			  #  call _printInt(t24)
	call _printInt
			  #  return 
	addq $8,%rsp
	ret
