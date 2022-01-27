#include <stdio.h>

#define V 5
#define INF 999999

void printSolution(int dist[][V])
{
	printf ("The following matrix shows the shortest distances between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				// formatted to print a string as
				// it Looks better than the Large Numeric Value
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

void floydWarshall (int graph[][V])
{
	int dist[V][V], i, j, k;

	// Initailized the solution matrix the same as the graph
	// ? maybe *memcopy* will be better? (in string.h)
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < V; k++)
	{
		// Pick all vertices as src one by one
		for (i = 0; i < V; i++)
		{
			// Pick all vertices as destination for the picked src vertex
			for (j = 0; j < V; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then the value of dist[i][j] is updated
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}


int main()
{

	int graph[V][V] =
					{
						{  0,   3,   8, INF,  -4},
						{INF,   0, INF,   1,   7},
						{INF,   4,   0, INF, INF},
						{  2, INF,  -5,   0, INF},
						{INF, INF, INF,   6,   0}
					};

	floydWarshall(graph); // Solves the Graph and Prints the Solution
	return 0;
}
