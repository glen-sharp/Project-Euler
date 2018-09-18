#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void)
{
	FILE* input_grid;
	int array[20][20], i, j, v1, v2, v3, v4, max = 0, tot;
	clock_t begin = clock();

	if ((input_grid = fopen("num3.txt", "r")) == NULL)
		printf("File open failed\n");
	else
		printf("File opened\n");

	for (j = 0; j < 20; j++)
		for (i = 0; i < 20; i++)
		{
			fscanf(input_grid, "%d", &array[j][i]);
			//printf("%d", array[j][i]);
		}

	for (j = 0; j < 20; j++)
	{
		printf("\n");
		for (i = 0; i < 20; i++)
			printf("%d ", array[j][i]);
	}

	for (j = 0; j < 20; j++)
	{
		for (i = 0; i < 17; i++)
		{
			v1 = array[j][i];
			v2 = array[j][i + 1];
			v3 = array[j][i + 2];
			v4 = array[j][i + 3];
			tot = v1*v2*v3*v4;
			if (tot > max)
			{
				max = tot;
				//printf("%d*%d*%d*%d=%d\n", v1, v2, v3, v4, tot);
			}
		}
	}

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 17; j++)
		{
			v1 = array[j][i];
			v2 = array[j + 1][i];
			v3 = array[j + 2][i];
			v4 = array[j + 3][i];
			tot = v1*v2*v3*v4;
			if (tot > max)
			{
				max = tot;
				//printf("%d*%d*%d*%d=%d    array[%d][%d]\n", v1, v2, v3, v4, tot, j, i);
			}
		}
	}

	for (i = 0; i < 17; i++)
	{
		for (j = 0; j < 17; j++)
		{
			v1 = array[i][j];
			v2 = array[i + 1][j + 1];
			v3 = array[i + 2][j + 2];
			v4 = array[i + 3][j + 3];
			tot = v1*v2*v3*v4;
			if (tot > max)
			{
				max = tot;
				//printf("%d*%d*%d*%d=%d    array[%d][%d]\n", v1, v2, v3, v4, tot, i, j);
			}
		}
	}

	for (i = 0; i < 17; i++)
	{
		for (j = 0; j < 17; j++)
		{
			v1 = array[i][j + 3];
			v2 = array[i + 1][j + 2];
			v3 = array[i + 2][j + 1];
			v4 = array[i + 3][j];
			tot = v1*v2*v3*v4;
			if (tot > max)
			{
				max = tot;
				//printf("%d*%d*%d*%d=%d    array[%d][%d]\n", v1, v2, v3, v4, tot, i, j);
			}
		}
	}

	printf("%d", max);
	fclose(input_grid);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);
	return 0;
}