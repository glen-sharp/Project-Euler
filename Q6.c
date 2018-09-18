#include <stdio.h>
#include <math.h>

int main(void)
{
	int i, diff = 0, sum_of = 0, square_of = 0;

	for (i = 1; i <= 100; i++)
	{
		sum_of += pow(i, 2);
		square_of += i;
	}
	printf("Difference = %d\n", diff = (pow(square_of, 2)) - sum_of);

	return 0;
}