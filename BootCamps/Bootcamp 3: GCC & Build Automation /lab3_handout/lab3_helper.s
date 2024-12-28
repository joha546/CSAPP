	.file	"lab3_helper.c"
	.text
	.globl	helper_func
	.type	helper_func, @function
helper_func:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$45, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$213, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	$24, -16(%rbp)
	movl	-16(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, -20(%rbp)
	movl	-8(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	negl	%eax
	movl	-20(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-20(%rbp), %eax
	imull	$45, %eax, %eax
	movslq	%eax, %rdx
	imulq	$2078471887, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$8, %edx
	sarl	$31, %eax
	subl	%eax, %edx
	imull	$100900090, %edx, %eax
	movl	%eax, -28(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	subl	-28(%rbp), %eax
	movl	%eax, -12(%rbp)
	addl	$1, -4(%rbp)
.L2:
	movl	-8(%rbp), %eax
	imull	$100, %eax, %eax
	cmpl	%eax, -4(%rbp)
	jl	.L3
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	helper_func, .-helper_func
	.ident	"GCC: (Debian 14.2.0-8) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
