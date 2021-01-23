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
	
	long long sum, diff;

	asm(".intel_syntax noprefix;"
		"mov rcx, rax;"  // rcx = rax
		"add rax, rbx;"  // rax += rbx
		"sub rcx, rbx;"  // rcx -= rbx
		".att_syntax noprefix;"
		: "=a" (sum), "=c" (diff) // outputs
		: "a" (n1), "b" (n2) // inputs
		: // clobbers
		);
	
	print_int(sum);
	print_int(diff);
	
	return 0;
}
