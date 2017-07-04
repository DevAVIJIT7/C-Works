#include <stdio.h>

void bubbleSort(int[], int);
void swap(int*, int*);

void bubbleSort(int arr[], int n)
{
	int i, j;

	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
    
    for (i = 0; i <= n-1; i++)
	  printf("%d\t", arr[i]);
}

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int arr[] = {7, 8, 2, 6, 5, 3};
	bubbleSort(arr, 6);
}