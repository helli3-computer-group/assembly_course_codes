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

long long var1;
unsigned long long var2;
int var3;
short int var4;
char var5;

int main()
{
	var1 = 100;
	var2 = read_unsigned_int();
	var3 = read_int();
	var4 = read_int();
	var5 = read_int();

	asm(".intel_syntax noprefix;"
		"mov rax, qword ptr [rip + var1];"
		"add rax, rax;"
		"mov qword ptr [rip + var1], rax;"
		"add qword ptr [rip + var2], 50;"
		"sub dword ptr [rip + var3], 200;"
		"inc word ptr [rip + var4];"
		"neg byte ptr [rip + var5];"
		"dec byte ptr [rip + var5];"
		".att_syntax noprefix;"
		: // outputs
		: // inputs
		: // clobbers
		);

	print_nl();
	print_int(var1);
	print_unsigned_int(var2);
	print_int(var3);
	print_int(var4);
	print_int(var5);
	
	return 0;
}
