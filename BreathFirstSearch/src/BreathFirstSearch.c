#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

typedef struct
{
	int items[SIZE];
	int front;
	int rear;
}queue;

queue *createQueue();
void enqueue(queue *q, int);
int dequeue(queue *q);
void display(queue *q);
int isEmpty(queue *q);
void printQueue(queue *q);

typedef struct node
{
	int vertex;
	struct node *next;
}node;

node *createNode(int);

typedef struct
{
	int numVertices;
	node **adjLists;
	int *visited;
}Graph;

// BFS algorithm
void bfs(Graph *graph, int startVertex)
{
	queue *q = createQueue();

	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);

	while (!isEmpty(q))
	{
		printQueue(q);
		int currentVertex = dequeue(q);
		printf("Visited %d\n", currentVertex);

		node *temp = graph->adjLists[currentVertex];

		while (temp)
		{
			int adjVertex = temp->vertex;

			if (graph->visited[adjVertex] == 0)
			{
				graph->visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;
		}
	}
}

// Creating a node
node *createNode(int v)
{
	node *newNode = malloc(sizeof(node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

// Creating a graph
Graph *createGraph(int vertices)
{
	Graph *graph = malloc(sizeof(Graph));
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

// Add edge
void addEdge(Graph *graph, int src, int dest)
{
	// Add edge from src to dest
	node *newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	// Add edge from dest to src
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

// Create a queue
queue *createQueue()
{
	queue *q = malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

// Check if the queue is empty
int isEmpty(queue *q)
{
	if (q->rear == -1)
		return 1;
	else
		return 0;
}

// Adding elements into queue
void enqueue(queue *q, int value)
{
	if (q->rear == SIZE - 1)
		printf("\nQueue is Full!!");
	else
	{
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}

// Removing elements from queue
int dequeue(queue *q)
{
	int item;
	if (isEmpty(q))
	{
		printf("Queue is empty");
		item = -1;
	}
	else
	{
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear)
		{
			printf("Resetting queue ");
			q->front = q->rear = -1;
		}
	}
	return item;
}

void printQueue(queue *q)
{
	int i = q->front;

	if (isEmpty(q))
		printf("Queue is empty");

	else
	{
		printf("\nQueue contains \t");
		for (i = q->front; i < q->rear + 1; i++)
		{
			printf("%c ", q->items[i] + 65);
		}
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
	bfs(graph, 0);

	return 0;
}