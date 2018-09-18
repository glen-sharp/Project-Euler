#include <stdio.h>
#include <math.h>
#include <time.h>

//needs work - takes too long

long long int div(long long int x)
{
	long long int i, count = 2;
	for (i = 2; i <= x/2; i++)
	{
		if (x%i == 0)
			count++;
	}
	return count;
}

int main(void)
{
	long long int y = 1, x = 0, count = 1, i;
	clock_t begin = clock();

	do
	{
		x += y;
		y = y + 1;
		printf("%lld: %lld\n", x, div(x));
	} while (div(x) < 500);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	
	
	return 0;
}