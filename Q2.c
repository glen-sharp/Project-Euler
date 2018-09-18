#include <stdio.h>
#include <time.h>

int main(void)
{
	int i, next = 2, current = 1, before = 1, lim, sum = 0;
	clock_t begin = clock();

	do 
	{
		printf("%d ", current);
		if (current % 2 == 0)
			sum += current;
		before = current;
		current = next;
		next = current + before;
	} while (current <= 4000000);

	printf("\nsum of terms = %d\n", sum);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}