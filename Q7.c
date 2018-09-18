#include <stdio.h>

int prime(long int x)
{
	long int i = 2, count = 0;

	do
	{
		if (x%i == 0)
			count++;
		i++;
	} while (count == 0 && i < x);
	return count;
}

int main(void)
{
	long int num = 1, z = 1;
	
	while (z != 10001)
	{
		num++;
		if (prime(num) == 0)
		{
			z++;
			printf("%ld\n", num);
		}
	}
	printf("\n");
	printf("10001st prime = %ld\n", num);
	return 0;
}