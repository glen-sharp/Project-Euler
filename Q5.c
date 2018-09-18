#include <stdio.h>
#include <time.h>

int div(long long int x)
{
	int i = 1, count = 0;

	do
	{
		if (x%i == 0)
			count++;
		i++;
	} while (i <= 20);

	return count;
}


int main(void)
{
	long long int num = 20;
	clock_t begin = clock();

	while (div(num) != 20)
	{
		num+=20;
		printf("%lld\n", num);
	}

	printf("\n");
	printf("Lowest = %lld\n", num);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}