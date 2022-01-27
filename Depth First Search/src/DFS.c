#include <stdio.h>
#include <stdlib.h>

struct node
{
	int vertex;
	struct node *next;
};

typedef struct node node;

struct Graph
{
	int numVertices;
	int *visited;
	node **adjLists;
};

typedef struct Graph Graph;

void DFS(Graph *graph, int vertex)
{
	node *adjList = graph->adjLists[vertex];
	node *temp = adjList;
	graph->visited[vertex] = 1;
	printf("Visited %c \n", vertex + 65);
	while (temp != NULL)
	{
		int connectedVertex = temp->vertex;
		if (graph->visited[connectedVertex] == 0)
			DFS(graph, connectedVertex);

		temp = temp->next;
	}
}

node *createNode(int v)
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

Graph *createGraph(int vertices)
{
	Graph *graph = malloc(sizeof( Graph));
	graph->numVertices = vertices;
	graph->adjLists = malloc(vertices * sizeof(node *));
	graph->visited = malloc(vertices * sizeof(int));
	int i;
	for (i = 0; i < vertices; i++)
	{
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

void addEdge(Graph *graph, int src, int dest)
{

	struct node *newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(Graph *graph)
{
	for (int v = 0; v < graph->numVertices; v++)
	{
		struct node *temp = graph->adjLists[v];
		printf("\n Adjacency list of vertex %d\n ", v);
		while (temp)
		{
			printf("%c -> ", temp->vertex +64);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	Graph *graph = createGraph(7);

	addEdge(graph, 0, 1);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 5);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 6, 3);

	printGraph(graph);
	printf("\n");
	DFS(graph, 0);
	return 0;
}
