	.text
			  # _main () (i, b)
			  # t1	%rax
			  # t2	%rbx
			  # b	%rbx
			  # t3	%rax
			  # t4	%rax
			  # t5	%rax
			  # t6	%rcx
			  # t7	%rcx
			  # t8	%rdx
			  # i	%rdi
			  # t9	%rdx
	.p2align 4,0x90
	.globl_main
_main:
	pushq %rbx
			  #  t1 = 2 * 4
	movq $4,%r10
	movq $2,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  t2 = 2 + t1
	movq $2,%r11
	movq %r11,%rbx
	addq %rax,%rbx
			  #  t3 = 9 / 3
	movq $3,%r10
	movq $9,%r11
	movq %r11,%rax
	cqto
	idivq %r10
			  #  t4 = t2 - t3
	movq %rax,%r10
	movq %rbx,%rax
	subq %r10,%rax
			  #  i = t4
	movq %rax,%rdi
			  #  t5 = true
	movq $1,%rax
			  #  t6 = 1 > 2
	movq $2,%r10
	movq $1,%r11
	cmpq %r10,%r11
	setg %cl
	movzbq %cl,%rcx
			  #  if t6 == true goto L0
	movq $1,%r11
	cmpq %r11,%rcx
	je main_L0
			  #  t7 = false
	movq $0,%rcx
			  #  t8 = 3 < 4
	movq $4,%r10
	movq $3,%r11
	cmpq %r10,%r11
	setl %dl
	movzbq %dl,%rdx
			  #  if t8 == false goto L1
	movq $0,%r11
	cmpq %r11,%rdx
	je main_L1
			  #  t9 = !false
	movq $0,%r10
	movq %r10,%rdx
	notq %rdx
			  #  if t9 == false goto L1
	movq $0,%r11
	cmpq %r11,%rdx
	je main_L1
			  #  t7 = true
	movq $1,%rcx
			  # L1:
main_L1:
			  #  if t7 == true goto L0
	movq $1,%r11
	cmpq %r11,%rcx
	je main_L0
			  #  t5 = false
	movq $0,%rax
			  # L0:
main_L0:
			  #  b = t5
	movq %rax,%rbx
			  #  call _printInt(i)
	call _printInt
			  #  call _printBool(b)
	movq %rbx,%rdi
	call _printBool
			  #  return 
	popq %rbx
	ret
