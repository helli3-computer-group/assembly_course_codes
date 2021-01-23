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
	long long a, b;
	long long mul, div, rem;
	
	a = read_int();
	b = read_int();

/*	mul = 0;
	
	long long t = b;
	
	while (t > 0)
	{
		mul += a;
		t -= 1;
	}
	
	div = 0;
	while (a >= b)
	{
		div += 1;
		a -= b;
	}
	rem = a;*/

	asm(".intel_syntax noprefix;"
		"mov r15, rbx;"
		"mov rcx, 0;"
		""
		"cmp r15, 0;"
		"jle mul_loop_end;"
		""
		"mul_loop: "
		"	add rcx, rax;"
		"	dec r15;"
		"	jne mul_loop;"
		"mul_loop_end: "
		""
		"mov rdx, 0;"
		""
		"div_loop: "
		"	cmp rax, rbx;"
		"	jl div_loop_end;"
		"	"
		"	inc rdx;"
		"	sub rax, rbx;"
		"	jmp div_loop;"
		"div_loop_end:"
		".att_syntax noprefix;"
		: "=c" (mul), "=d" (div), "=a" (rem) // outputs
		: "a" (a), "b" (b) // inputs
		: // clobbers
		);

	print_int(mul);
	print_int(div);
	print_int(rem);

	return 0;
}
