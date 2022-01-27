#include <stdio.h>

int binarySearch(int num[], int low, int high, int find)
{
    if (low > high)
        return -1;

    int middle = low + (high - low) / 2;

    if (num[middle] == find)
        return middle;

    if (find < num[middle])
    {
        return binarySearch(num, low, middle - 1, find);
    }

    else
    {
        return binarySearch(num, middle + 1, high, find);
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}


int main()
{
    int arr[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Enter Element Number %d:\t", i + 1);
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr, 5);

    int x;
    printf("Enter Element Number to find:\t");
    scanf("%d",&x);

    int result = binarySearch(arr, 0, 5 - 1, x);

    if(result == -1)
        printf("Element is not present in array");

    else
        printf("Element is present at index %d",result);

    return 0;
}