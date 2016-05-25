	.text
			  # _go () 
			  # t1	%rax
	.p2align 4,0x90
	.globl_go
_go:
	subq $8,%rsp
			  #  t1 = call _value(true)
	movq $1,%rdi
	call _value
			  #  return t1
	addq $8,%rsp
	ret
			  # _value (cond) (i, j, k)
			  # i	%rax
			  # j	%rcx
			  # k	%rax
			  # cond	%rdi
	.p2align 4,0x90
	.globl_value
_value:
	subq $8,%rsp
			  #  i = 5
	movq $5,%rax
			  #  j = 6
	movq $6,%rcx
			  #  if cond == false goto L0
	movq $0,%r11
	cmpq %r11,%rdi
	je value_L0
			  #  k = i
			  #  goto L1
	jmp value_L1
			  # L0:
value_L0:
			  #  k = j
	movq %rcx,%rax
			  # L1:
value_L1:
			  #  return k
	addq $8,%rsp
	ret
			  # _main () 
			  # t2	%rdi
	.p2align 4,0x90
	.globl_main
_main:
	subq $8,%rsp
			  #  t2 = call _go()
	call _go
	movq %rax,%rdi
			  #  call _printInt(t2)
	call _printInt
			  #  return 
	addq $8,%rsp
	ret
