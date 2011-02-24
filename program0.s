	.file	"program.c"
	.text
.globl square
	.type	square, @function
square:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	imull	8(%ebp), %eax
	popl	%ebp
	ret
	.size	square, .-square
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	$10, 32(%esp)
	movl	$0, 44(%esp)
	movl	$0, 40(%esp)
	movl	$24, (%esp)
	call	square
	movl	$.LC0, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	printf
	movl	$1, 36(%esp)
	jmp	.L4
.L5:
	movl	32(%esp), %eax
	sall	$2, %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	28(%esp)
	movl	%eax, %edx
	addl	28(%esp), %edx
	movl	32(%esp), %eax
	leal	(%eax,%eax), %ecx
	movl	44(%esp), %eax
	imull	40(%esp), %eax
	leal	(%ecx,%eax), %eax
	leal	(%edx,%eax), %eax
	movl	%eax, 28(%esp)
	movl	40(%esp), %eax
	addl	%eax, %eax
	movl	%eax, 40(%esp)
	movl	$0, 40(%esp)
	movl	40(%esp), %eax
	imull	36(%esp), %eax
	addl	$24, %eax
	movl	%eax, 40(%esp)
	movl	$1, (%esp)
	call	square
	movl	%eax, 40(%esp)
	addl	$1, 36(%esp)
.L4:
	movl	36(%esp), %eax
	cmpl	32(%esp), %eax
	jl	.L5
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	square
	movl	%eax, 40(%esp)
	movl	$.LC0, %eax
	movl	40(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$1, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5"
	.section	.note.GNU-stack,"",@progbits
