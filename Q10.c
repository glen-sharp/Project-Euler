#include <stdio.h>
#include <math.h>
#include <time.h>
#define LIMIT 2000000 

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
	long int i;
	long long int sum = 2;
	clock_t begin = clock();

	for (i = 3; i < LIMIT; i+=2)
	{
		if (prime(i) == 0)
		{
			sum += i;
			printf("%ld\n", i);
		}
	}

	printf("%lld\n", sum);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}