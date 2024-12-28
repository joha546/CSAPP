	.file	"lab3.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"You are taking this class: %d %d \n"
	.text
	.globl	fibonacci
	.type	fibonacci, @function
fibonacci:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -36(%rbp)
	movl	$40, -20(%rbp)
	movl	$0, %eax
	call	helper_func@PLT
	movl	%eax, %ecx
	movl	-36(%rbp), %eax
	movl	%eax, %edx
	movl	%ecx, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpl	$1, -36(%rbp)
	jg	.L2
	movl	-36(%rbp), %eax
	jmp	.L3
.L2:
	movl	-36(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fibonacci
	movl	%eax, %ebx
	movl	-36(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	fibonacci
	addl	%ebx, %eax
.L3:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fibonacci, .-fibonacci
	.section	.rodata
.LC1:
	.string	"fib(%d) = %d\n"
	.align 8
.LC3:
	.string	"clocks ticks: %f \nTime in seconds taken by CPU: %f \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	call	clock@PLT
	movq	%rax, -8(%rbp)
	movl	$25, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	fibonacci
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2, -12(%rbp)
	call	clock@PLT
	subq	-8(%rbp), %rax
	movq	%rax, -8(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2sdq	-8(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	pxor	%xmm2, %xmm2
	cvtsi2sdq	-8(%rbp), %xmm2
	movq	%xmm2, %rax
	movsd	-24(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1093567616
	.ident	"GCC: (Debian 14.2.0-8) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
