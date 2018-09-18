#include <stdio.h>
#include <math.h>
#include <time.h>

long long int product(int array1[], int x)
{
	int p;
	long long int q = 1;

	for (p = x; p < (x+13); p++)
	{
		q *= array1[p];
	}
	return q;
}

int main(void)
{
	FILE* input_num;
	int array[1000], i, j = 0, k, z, element;
	long long int max = 0, ans;
	clock_t begin = clock();
	
	if ((input_num = fopen("num.txt", "r")) == NULL)
		printf("File open failed\n");
	else
		printf("File opened\n");
	
	for (i = 0; i < 1000; i++)
		fscanf(input_num, "%1d", &array[i]);
	
	for (j = 0; j <= 986; j++)
	{
		if (product(array, j) > max)
		{
			max = product(array, j);
			element = j;
		}
		printf("%d:%lld ", j, product(array, j));
	}


	printf("\n\nGreatest product = %lld\n", max);

	printf("Thirteen numbers that make this are :\n");
	for (z = element; z < (element + 13); z++)
		printf("%d ", array[z]);

	fclose(input_num);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime = %lf s\n", time_spent);

	return 0;
}