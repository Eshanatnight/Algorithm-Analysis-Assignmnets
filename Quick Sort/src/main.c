#include<stdio.h>

/* A utility function to swap two elements */
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Partition function  */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Enter %d Element: ", i+1);
        scanf("%d",&arr[i]);
    }
    quickSort(arr, 0, 4);
	printf("\n\nSorted array: \n");
	printArray(arr, 5);
	return 0;
}
