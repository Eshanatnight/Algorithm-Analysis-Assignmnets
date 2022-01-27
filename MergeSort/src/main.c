#include <stdio.h>

//Generic Functions
//For Array Control

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void getArray(int *a, int size)
{
    printf("Enter The Elements: \n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void printArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

//Functions For
//Merge Sort

void merge(int *arr, int l, int m, int r)
{

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {

        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }

        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {

        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {

        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{

    if (l < r)
    {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    /*
    int arr[] = {66, 44, 99, 55, 11, 88, 22, 77, 33};
    int x = sizeof(arr) / sizeof(arr[0]);
    */
    int ar[5];
    int x = 5;

    getArray(ar, x);

    mergeSort(ar, 0, x - 1);
    printf("Sorted array: \n");
    printArray(ar, x);
}