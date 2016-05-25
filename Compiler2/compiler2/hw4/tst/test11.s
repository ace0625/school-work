	.text
			  # _go () (a, b, c, x)
			  # a	%rax
			  # t1	%rcx
			  # b	%rcx
			  # t2	%rdx
			  # t3	%rsi
			  # c	%rax
			  # x	%rax
	.p2align 4,0x90
	.globl_go
_go:
	subq $8,%rsp
			  #  a = true
	movq $1,%rax
			  #  t1 = !a
	movq %rax,%rcx
	notq %rcx
			  #  b = t1
			  #  t2 = true
	movq $1,%rdx
			  #  t3 = false
	movq $0,%rsi
			  #  if a == false goto L1
	movq $0,%r11
	cmpq %r11,%rax
	je go_L1
			  #  if b == false goto L1
	movq $0,%r11
	cmpq %r11,%rcx
	je go_L1
			  #  t3 = true
	movq $1,%rsi
			  # L1:
go_L1:
			  #  if t3 == true goto L0
	movq $1,%r11
	cmpq %r11,%rsi
	je go_L0
			  #  if a == true goto L0
	movq $1,%r11
	cmpq %r11,%rax
	je go_L0
			  #  t2 = false
	movq $0,%rdx
			  # L0:
go_L0:
			  #  c = t2
	movq %rdx,%rax
			  #  if c == false goto L2
	movq $0,%r11
	cmpq %r11,%rax
	je go_L2
			  #  x = 1
	movq $1,%rax
			  #  goto L3
	jmp go_L3
			  # L2:
go_L2:
			  #  x = 0
	movq $0,%rax
			  # L3:
go_L3:
			  #  return x
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
