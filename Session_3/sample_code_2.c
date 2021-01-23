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
	long long o1, o2;
	
	n1 = read_int();
	n2 = read_int();

	asm(".intel_syntax noprefix;"
		"mov r8, rax;"
		"add r8, rbx;"
		""
		"cmp rax, 50;"
		"jle if_1_else;"
		"cmp r8, 100;"
		"jg if_1_else;"
		"if_1_if: "
		"	mov rcx, 1;"
		"	jmp if_1_end;"
		"if_1_else:"
		"	mov rcx, 0;"
		"if_1_end: "
		""
		"cmp rax, 50;"
		"jg if_2_if;"
		"cmp r8, 100;"
		"jle if_2_if;"
		"jmp if_2_else;"
		"if_2_if: "
		"	mov rdx, 1;"
		"	jmp if_2_end;"
		"if_2_else: "
		"	mov rdx, 0;"
		"if_2_end: "
		".att_syntax noprefix;"
		: "=c" (o1), "=d" (o2) // outputs
		: "a" (n1), "b" (n2) // inputs
		: "r8" // clobbers
		);

	print_int(o1);
	print_int(o2);

	return 0;
}
