#include <stdio.h>
#include <time.h>

int reverse(int x)
{
	int y = 0;
	while (x != 0)
	{
		y = (x % 10) + (y * 10);
		x = x / 10;
	}
	return y;
}

int main(void)
{
	long long int i, j, max = 0, i_max = 0, j_max = 0;
	clock_t begin = clock();

	for (i = 1; i < 1000; i++)
		for (j = 1; j < 1000; j++)
		{
			if ((i*j) == reverse(i*j) && i*j > max)
			{
				printf("%lld\n", i*j);
				max = i*j;
				i_max = i;
				j_max = j;
			}
		}
	printf("\nmax palindrome from two 3 digit numbers = %lld made from %lld*%lld\n", max, i_max, j_max);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}