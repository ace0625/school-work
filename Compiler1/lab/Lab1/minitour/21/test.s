	.file	"test.s"
	.globl	_Main_main
_Main_main:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$8,%esp
	movl	$0,%eax
	movl	%eax,-4(%ebp)
	movl	$0,%eax
	movl	%eax,-8(%ebp)
	jmp	l1
l0:
	movl	$1,%eax
	movl	-4(%ebp),%ecx
	addl	%ecx,%eax
	movl	%eax,-4(%ebp)
	movl	-4(%ebp),%eax
	movl	-8(%ebp),%ecx
	addl	%ecx,%eax
	movl	%eax,-8(%ebp)
l1:
	movl	$10,%eax
	movl	-4(%ebp),%ecx
	cmpl	%eax,%ecx
	jl	l0
	subl	$12,%esp
	movl	-8(%ebp),%eax
	pushl	%eax
	call	_print
	movl	%ebp,%esp
	popl	%ebp
	ret
