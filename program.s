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
	subl	$32, %esp
	movl	%ebx, 24(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 28(%esp)
	movl	$576, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	movl	$40, %ecx
	movl	%ecx, %edx
	movl	%ecx, %eax
	sarl	$31, %edx
	idivl	%ebx
	movl	%ecx, %edx
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	sarl	$31, %edx
	leal	20(%eax), %esi
	movl	%eax, %ebx
	movl	%ecx, %eax
	idivl	%esi
	movl	%ecx, %edx
	sarl	$31, %edx
	leal	40(%ebx,%eax), %ebx
	movl	%ecx, %eax
	idivl	%ebx
	leal	140(%ebx,%eax), %eax
	imull	%eax, %eax
	movl	%eax, 8(%esp)
	call	__printf_chk
	movl	$1, %eax
	movl	24(%esp), %ebx
	movl	28(%esp), %esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5"
	.section	.note.GNU-stack,"",@progbits
