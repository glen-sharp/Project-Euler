#include <stdio.h>
#include <time.h>

int main(void)
{
	int num, sum = 0, i;
	clock_t begin = clock();

	printf("Enter number: ");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		if (i % 5 == 0 || i % 3 == 0)
			sum += i;
	}
	printf("%d\n", sum);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}