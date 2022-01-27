//
// Created by eshan on 08-06-2021.
//
// C++ program using memoization
#include <stdio.h>
#include <limits.h>
#include <string.h>
//#include "utility.h"

int dp[100][100];  // a memorization table

// std min function
const int min (int first, int second)
{
    return (first > second) ? second : first;
}


// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++)
        dp[i][j] = min( dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);

    return dp[i][j];
}


int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

int main()
{
    int arr[] = { 30, 35, 15, 5, 10, 20, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp)); // uses the memset function to set the values of memorization table

    printf("Minimum number of multiplications is %d", MatrixChainOrder(arr, n));
}


