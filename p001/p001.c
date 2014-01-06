
#include <stdio.h>

int main(int argc, char *argv[])
{
	int sum, i;

	sum = 0;
	for (i = 0; i < 1000; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sum += i;
		}
	}
	printf("A soma dos numeros naturais menores que 1000 é %d\n", sum);
	return (0);
}

