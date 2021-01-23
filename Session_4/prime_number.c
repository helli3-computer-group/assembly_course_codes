#include <stdio.h>

long long read_int()
{
	long long input;
	
	scanf("%lld", &input);
	
	return input;
}

long long read_unsigned_int()
{
	unsigned long long input;
	
	scanf("%llu", &input);
	
	return input;
}

void print_int(long long output)
{
	printf("%lld\n", output);
}

void print_unsigned_int(unsigned long long output)
{
	printf("%llu\n", output);
}

void print_nl()
{
	printf("\n");
}

int main()
{
	unsigned long long n, o;
	
	n = read_unsigned_int();

	asm(".intel_syntax noprefix;"
		"mov rax, rbx;"
		"mov rdx, 0;"
		"mov r8, 2;"
		"div r8;"
		"mov r9, rax;"
		""
		"mov r8, 1;"
		"mov rcx, 2;"
		"loop: "
		"	cmp rcx, r9;"
		"	jg end_loop;"
		""
		"	mov rax, rbx;"
		"	mov rdx, 0;"
		"	div rcx;"
		""
		"	cmp rdx, 0;"
		"	jne continue_loop;"
		"		mov r8, 0;"
		"		jmp end_loop;"
		"	continue_loop: "
		"	inc rcx;"
		"	jmp loop;"
		"end_loop:"
		"mov rdx, r8;"
		".att_syntax noprefix;"
		: "=d" (o) // outputs
		: "b" (n) // inputs
		: "rax", "rcx", "r8", "r9"// clobbers
		);
	
	print_unsigned_int(o);
	
	return 0;
}
