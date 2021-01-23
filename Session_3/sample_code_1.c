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
	long long n1, n2;
	
	n1 = read_int();
	n2 = read_int();
	
	long long o1, o2;

	asm(".intel_syntax noprefix;"
		"cmp rax, rbx;"
		"jle if_1_else;"
		"if_1_if: "
		"	mov rcx, rax;"
		"	sub rcx, rbx;"
		"	jmp if_1_end;"
		"if_1_else: "
		"	mov rcx, rax;"
		"	add rcx, rbx;"
		"if_1_end: "
		""
		"mov rdx, rbx;"
		"cmp rax, 50;"
		"jle if_2_end;"
		"	mov rdx, rax;"
		"if_2_end: "
		".att_syntax noprefix;"
		: "=c" (o1), "=d" (o2) // outputs
		: "a" (n1), "b" (n2) // inputs
		: // clobbers
		);
	
	print_int(o1);
	print_int(o2);
	
	return 0;
}
