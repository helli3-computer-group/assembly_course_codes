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
	printf("%lld", output);
}

void print_unsigned_int(unsigned long long output)
{
	printf("%llu", output);
}

int main()
{
	asm(".intel_syntax noprefix;"
		".att_syntax noprefix;"
		: // outputs
		: // inputs
		: // clobbers
		);
	
	return 0;
}
