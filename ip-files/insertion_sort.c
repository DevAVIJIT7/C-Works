#include <stdio.h>

void insertionSort(int[], int);
void printArray(int[], int);

void insertionSort(int arr[], int n)
{
	int i, j, key;

	for (i=0; i<n; i++)
	{
		key = arr[i];

		j = i-1;
		while (j>=0 && key < arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void printArray(int arr[], int n)
{
	for (int i=0; i<n; i++)
		printf("%d\t", arr[i]);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    insertionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}