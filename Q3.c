#include <stdio.h>
#include <time.h>

int main(void)
{
	long long int i, j, k, num, max = 0, mod = 0;
	clock_t begin = clock();
	FILE* primes;
	int array[1000];

	primes = fopen("prime_numbers.txt", "r");

	for (j = 0; j < 1000; j++)
		array[j] = 0;

	for (j = 0; j < 1000; j++)
	{
		fscanf(primes, "%d", &array[j]);
		printf("%d  ", array[j]);
	}

	num = 600851475143;

	for (i = 0; i < 1000; i++)
	{
		if (num%array[i] == 0 && array[i] > max)
			max = array[i];
	}

	printf("Highest prime factor = %lld\n", max);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}