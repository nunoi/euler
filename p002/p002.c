
#include <stdio.h>

int main(int argc, char *argv[])
{
	int sum, i;
	int fib, old_fib, tmp;

	i = 0;
	sum = 2;
	old_fib = 1;
	fib = 2;
	while ((i++ < 1000000) && (fib < 1000000)) {
		tmp = fib + old_fib;
		old_fib = fib;
		fib = tmp;
		printf("%d\t%d\n", fib, sum);
		if (fib % 2 == 0)
			sum += fib;
	}
	printf("A soma dos nºs Fibonacci pares menores que 1.000.000 é %d\n",
		sum);
	return 0;
}
 
