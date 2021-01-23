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
	long long n;
	long long a, b, c, d;

	n = read_int();

	asm(".intel_syntax noprefix;"
		"mov r8, rax;" // r8 = rax
		"inc rax;"     // rax += 1
		"mov rbx, r8;" // rbx = r8
		"dec rbx;"     // rbx -= 1
		"mov rcx, r8;" // rcx = r8
		"neg rcx;"     // rcx = -rcx;
		"mov rdx, r8;" // rdx = r8
		"add rdx, 5;"  // rdx += 5
//		"mov r9, 5;"   // r9 = 5
//		"add rdx, r9;" // rdx += r9
		".att_syntax noprefix;"
		: "=a" (a), "=b" (b), "=c" (c), "=d" (d) // outputs
		: "a" (n) // inputs
		: "r8", "r9" // clobbers
		);
		
	print_int(a);
	print_int(b);
	print_int(c);
	print_int(d);
	
	return 0;
}
