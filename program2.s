	.file	"program.c"
	.text
	.p2align 4,,15
.globl square
	.type	square, @function
square:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	imull	%eax, %eax
	ret
	.size	square, .-square
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.text
	.p2align 4,,15
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%esi
	movl	$40, %esi
	pushl	%ebx
	movl	$1, %ebx
	subl	$24, %esp
	movl	$576, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	xorl	%ecx, %ecx
	.p2align 4,,7
	.p2align 3
.L4:
	movl	%esi, %edx
	movl	%esi, %eax
	sarl	$31, %edx
	addl	$1, %ebx
	idivl	%ecx
	cmpl	$10, %ebx
	leal	20(%ecx,%eax), %ecx
	jne	.L4
	imull	%ecx, %ecx
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	movl	%ecx, 8(%esp)
	call	__printf_chk
	addl	$24, %esp
	movl	$1, %eax
	popl	%ebx
	popl	%esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5"
	.section	.note.GNU-stack,"",@progbits
