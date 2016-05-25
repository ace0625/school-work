	.text
			  # _go () 
			  # t1	%rax
			  # t2	%rax
			  # t3	%rax
	.p2align 4,0x90
	.globl_go
_go:
	subq $8,%rsp
			  #  t1 = 1 < 2
	movq $2,%r10
	movq $1,%r11
	cmpq %r10,%r11
	setl %al
	movzbq %al,%rax
			  #  if t1 == false goto L0
	movq $0,%r11
	cmpq %r11,%rax
	je go_L0
			  #  call _printInt(1)
	movq $1,%rdi
	call _printInt
			  #  goto L1
	jmp go_L1
			  # L0:
go_L0:
			  #  t2 = 3 * 4
	movq $4,%r10
	movq $3,%r11
	movq %r11,%rax
	imulq %r10,%rax
			  #  t3 = t2 == 10
	movq $10,%r10
	cmpq %r10,%rax
	sete %al
	movzbq %al,%rax
			  #  if t3 == false goto L2
	movq $0,%r11
	cmpq %r11,%rax
	je go_L2
			  #  call _printInt(4)
	movq $4,%rdi
	call _printInt
			  #  goto L3
	jmp go_L3
			  # L2:
go_L2:
			  #  call _printInt(5)
	movq $5,%rdi
	call _printInt
			  # L3:
go_L3:
			  # L1:
go_L1:
			  #  return 6
	movq $6,%rax
	addq $8,%rsp
	ret
			  # _main () 
			  # t4	%rdi
	.p2align 4,0x90
	.globl_main
_main:
	subq $8,%rsp
			  #  t4 = call _go()
	call _go
	movq %rax,%rdi
			  #  call _printInt(t4)
	call _printInt
			  #  return 
	addq $8,%rsp
	ret
