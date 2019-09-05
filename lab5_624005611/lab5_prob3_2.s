	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc                      #
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	L_.str(%rip), %rax
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-20(%rbp), %edi
	addl	$1, %edi
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %esi
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"The value of i is %d\n"


.subsections_via_symbols

# The generated assembly code varies with the different optimization flags during the compilation command. The assembly code shown here is the generated assembly code without any optimization flags. Since this code is not optimized, it will contain unneccesary assembly statements.

# In "_main:", the register %rbp is pointing to the frame.

# In "Ltmp1:", the registers %rsp and %rbp point to the same location in the stack.

# In "Ltmp2:", the statements prior to "movl $1, -20(%rbp)" allocates the arguments for main in the stack, which are not used in the program. The program then sets i to 1 with the statement "movl $1, -20(%rbp), which will be pointed by the register %edi. i then gets incremented by 1 with the statement "addl $1, %edi" This incremented value is the one that will be printed when "_printf" is called; _ptintf is also not defined in here.

# L_.str is where the string to be printed is contained.
