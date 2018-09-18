#include <stdio.h>
#include <math.h>
#include <time.h>
#define limit 1E6

long long int count(long long int x)
{
	long long int count = 1;
	do
	{
		if (x % 2 == 0)
			x /= 2;
		else
			x = (3 * x) + 1;
		count++;
	} while (x != 1);
	return count;
}

int main(void)
{
	clock_t begin = clock();
	long long int i, max = 0, start;
	
	for (i = 3; i < limit; i++)
	{
		//printf("%d\n", i);
		if (count(i) > max)
		{
			max = count(i);
			start = i;
			printf("%lld: %lld\n", i, count(i));
		}
	}

	printf("%lld\n", start);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}