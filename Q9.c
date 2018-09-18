#include <stdio.h>
#include <math.h>
#include <time.h>
#define limit 1E3

long int square(int x)
{
	long int a;
	a = (long int)sqrt((double)x);
	if (a*a == x)
		return a;
	else
		return 0;
}

int main(void)
{
	long int a = 3, b, c, lim = 0;
	clock_t begin = clock();
	
	do
	{
		a++;
		b = 1;
		do
		{
			b++;
			c = pow(a, 2) + pow(b, 2);
			lim++;
		} while (square(c) == 0 && b != limit);
		if (((a*a) + (b*b)) == (c))
			printf("%ld %ld %ld\n", a, b, (int)sqrt(c));
	} while ((a + b + (int)sqrt(c)) != 1000);

	printf("%ld^2 + %ld^2 = %ld^2\n", a, b, square(c));
	printf("%ld\n", a*b*square(c));
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}