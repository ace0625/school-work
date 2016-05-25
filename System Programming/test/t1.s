	.file	"t1.c"
	.text
	.globl	ff
	.type	ff, @function
ff:
.LFB0:
	.cfi_startproc
	imull	$30, %edi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	ff, .-ff
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
