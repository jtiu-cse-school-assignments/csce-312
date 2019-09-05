//File named “lab5_prob6.c” 
#include <stdio.h>
int very_fast_function(int i){
    
    __asm( "irmovl $15, %eax\n\t"
          "rmmovl %eax, 4(%ebp)\n\t"
          "rmmovl %eax, 8(%ebp)\n\t"
          "irmovl $1, %eax\n\t"
          "rmmovl %eax, 12(%ebp)\n\t"
          "irmovl $63, %eax\n\t"
          "rmmovl %eax, 16(%ebp)\n\t"
          "irmovl $1, %eax\n\t"
          "rmmovl %eax, 20(%ebp)\n\t"
          "irmovl $1024, %eax\n\t"
          "rmmovl %eax, 24(%ebp)\n\t"
          "irmovl $1, %eax\n\t"
          "rmmovl %eax, 28(%ebp)\n\t"
        
          "adder:\n\t"
          "mrmovl 4(%ebp), %eax\n\t"
          "mrmovl 8(%ebp), %edi\n\t"
          "addl %eax, %edi\n\t"
          "rmmovl %edi, 4(%ebp)\n\t"
          "mrmovl 12(%ebp), %eax\n\t"
          "mrmovl 28(%ebp), %ecx\n\t"
          "mrmovl 12(%ebp), %edx\n\t"
          "addl %ecx, %eax\n\t"
          "rmmovl %eax, 12(%ebp)\n\t"
          "mrmovl 16(%ebp), %esi\n\t"
          "subl %esi, %edx\n\t"
          "jl adder\n\t"
 
          "xorl %esi, %esi\n\t"
          "xorl %edi, %edi\n\t"
          "xorl %edx, %edx\n\t"
 
          "mrmovl 4(%ebp), %eax\n\t"
          "mrmovl 20(%ebp), %ecx\n\t"
          "addl %ecx, %eax\n\t"
          "mrmovl 24(%ebp), %ecx\n\t"
          "subl %eax, %ecx\n\t"
          "jl itsGreater\n\t"
 
          "mrmovl 20(%ebp), %eax\n\t"
          "xorl %eax, %eax\n\t"
          "xorl %ecx, %ecx\n\t"
          "rmmovl %ecx, 4(%ebp)\n\t"
          "halt\n\t"
 
          "itsGreater:\n\t"
          "mrmovl 8(%ebp), %eax\n\t"
          "mrmovl 28(%ebp), %ecx\n\t"
          "addl %ecx, %eax\n\t"
          "rmmovl %eax, 4(%ebp)\n\t"
          "xorl %ecx, %ecx\n\t"
          "halt\n\t"

 );
	
int main(int argc, char *argv[]) {
	int i;
	i=40;
	printf("The function value of i is %d\n", very_fast_function(i) ); return 0;
}
    

/* 
 * ******This is the working y86 assembly code for int very_fast_function(int i)*******
 
_main:
irmovl $15, %eax #set i to 40 in eax
jmp _very_fast_function #call _very_fast_function:

_very_fast_function:
rmmovl %eax, 4(%ebp) #store i to 4(%ebp) : the val of i to be multiplied
rmmovl %eax, 8(%ebp)
irmovl $1, %eax #set eax to 1
rmmovl %eax, 12(%ebp) #store eax to 70(%ebp) : the value to be sub with 8()
irmovl $63, %eax #set eax to 64
rmmovl %eax, 16(%ebp) #store eax to 8(%ebp) : multiplier
irmovl $1, %eax #set eax to 1
rmmovl %eax, 20(%ebp) #store eax to 12(%ebp) : to be added 1 to i*64
irmovl $1024, %eax #set eax to 1024
rmmovl %eax, 24(%ebp) #store eax to 16(%esp) : to be compared
irmovl $1, %eax #set eax to 1
rmmovl %eax, 28(%ebp) #store eax to 20(%esp) : incrementer

adder:
mrmovl 4(%ebp), %eax #retrieve 4(%ebp) to eax
mrmovl 8(%ebp), %edi
addl %eax, %edi #add eax to eax
rmmovl %edi, 4(%ebp) #store eax to 4(%ebp)

mrmovl 12(%ebp), %eax #retrieve 8(%ebp) to eax
mrmovl 28(%ebp), %ecx #retrieve 24() to ecx
mrmovl 12(%ebp), %edx #retrieve 8() to edx
addl %ecx, %eax #add ecx eax
rmmovl %eax, 12(%ebp) #store eax to 8()

mrmovl 16(%ebp), %esi #retrieve 12() to edx
subl %esi, %edx #subtract ecx edx
jl adder #jl adder


xorl %esi, %esi
xorl %edi, %edi
xorl %edx, %edx

mrmovl 4(%ebp), %eax
mrmovl 20(%ebp), %ecx
addl %ecx, %eax
mrmovl 24(%ebp), %ecx
subl %eax, %ecx
jl itsGreater

mrmovl 20(%ebp), %eax
xorl %eax, %eax
xorl %ecx, %ecx
rmmovl %ecx, 4(%ebp)

halt

itsGreater:
mrmovl 8(%ebp), %eax
mrmovl 28(%ebp), %ecx
addl %ecx, %eax
rmmovl %eax, 4(%ebp)
xorl %ecx, %ecx
halt
*/