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
	unsigned long long n;
	unsigned long long f;

	n = read_unsigned_int();

	asm(".intel_syntax noprefix;"
		"mov rax, 1;"
		"mov rcx, 1;"
		""
		"fact_loop: "
		"	cmp rcx, rbx;"
		"	jg fact_loop_end;"
		"	"
		"	mul rcx;"
		"	inc rcx;"
		"	jmp fact_loop;"
		"fact_loop_end: "
		".att_syntax noprefix;"
		: "=a" (f) // outputs
		: "b" (n) // inputs
		: "rcx", "rdx" // clobbers
		);
	
	print_unsigned_int(f);
	
	return 0;
}
