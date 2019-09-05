	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
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
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello, world\n"


.subsections_via_symbols

# The generated assembly code varies with the different optimization flags during the compilation command. The assembly code shown here is the generated assembly code without any optimization flags. Since this code is not optimized, it will contain unneccesary assembly statements.

# In "_main:", the register %rbp is pointing to the frame.

# In "Ltmp1:", the registers %rsp and %rbp point to the same location in the stack.

# In "Ltmp2:", the statements prior to "callq _printf" allocates the arguments for main in the stack, which are not used in the program. The program then calls _printf, which is not defined in the assembly file, and prints out "Hello, world." Since the program ends with a return 0 statement, this is done with the "xorl %ecx, %ecx" that sets %ecx to 0 and "retq" for returning.

# L_.str is where the string to be printed is contained.
