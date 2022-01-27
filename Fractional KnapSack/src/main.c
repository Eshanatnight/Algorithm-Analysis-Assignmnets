#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int value, weight;
}Item;

int cmparator(const void * a, const void * b)
{
    Item* A = (Item*)a;
    Item* B = (Item*)b;
	double r1 = (double)A->value / (double)A->weight;
	double r2 = (double)B->value / (double)B->weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
	qsort(arr, n, sizeof(Item), cmparator); // uses the qsort function found in stdlibfor ease of use and less code towrte

	int curWeight = 0; // Current weight in knapsack
	double finalvalue = 0.0; // value in Knapsack

	for (int i = 0; i < n; i++)
    {
		if (curWeight + arr[i].weight <= W)
        {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}

		else
        {
			int remain = W - curWeight;
			finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
			break;
		}
	}

	return finalvalue;
}

int main()
{
	int W = 60; // Weight of knapsack
	Item arr[] = { { 6, 6 }, { 2, 10 }, { 1, 3 }, { 8, 5 }, { 3, 1 }, { 5, 3 } };

	int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum value we can obtain = %g", fractionalKnapsack(W, arr, n));
	return 0;
}
