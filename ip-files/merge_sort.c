#include <stdio.h>

void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void printArray(int[], int);

void merge(int arr[], int l, int m, int r)
{
	int n1, n2, i, j, k;
	n1 = m - l + 1;
	n2 = r - m;

	int L1[n1], L2[n2];

	for (i=0; i<n1; i++)
		L1[i] = arr[l+i];
	for (j=0; j<n2; j++)
		L2[j] = arr[m+j+1];

	i = 0;
	j = 0;
	k = l;

	while (i<n1 && j<n2)
	{
		if (L1[i] <= L2[j])
		{
			arr[k] = L1[i];
			i++;
		}
		else
		{
			arr[k] = L2[j];
			j++;
		}
		k++;
	}

	while (i<n1)
	{
		arr[k] = L1[i];
		i++;
		k++;
	}

	while (j<n2)
	{
		arr[k] = L2[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l<r)
	{
		int mid = (l+r)/2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);

		merge(arr, l, mid, r);
	}
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}