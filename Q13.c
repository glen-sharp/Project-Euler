#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void)
{
	FILE* input_num;
	clock_t begin = clock();
	int i, j, array[100][50], sum[52], x = 0;

	if ((input_num = fopen("problem_13.txt", "r")) == NULL)
		printf("File open failed\n");
	else
		printf("File opened\n");

	for (i = 0; i < 100; i++)
		for (j = 0; j < 50; j++)
			fscanf(input_num, "%1d", &array[i][j]);

	for (i = 0; i < 100; i++)
	{
		printf("\n");
		for (j = 0; j < 50; j++)
			printf("%d", array[i][j]);
	}

	for (i = 0; i < 52; i++)
		sum[i] = 0;

	for(i = 0; i < 50; i++)
		for (j = 0; j < 100; j++)
		{
			sum[i + 2] += array[j][i];
		}


	for (i = 51; i >= 0; i--)
	{
		if (sum[i] >= 10)
		{
			sum[i - 1] += (int)(sum[i] / 10);
			sum[i] = sum[i] % 10;
		}
	}

	for (i = 0; i < 10; i++)
		printf("%d", sum[i]);

	fclose(input_num);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}