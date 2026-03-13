#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} *NODE;

typedef struct List {
    NODE head;
} *LIST;

typedef struct graph {
    int numVertices;
    LIST arr;
} *GRAPH;

NODE newAdjNode(int dest)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

GRAPH createGraph(int v)
{
    GRAPH g = (GRAPH)malloc(sizeof(struct graph));
    g->numVertices = v;

    g->arr = (LIST)malloc(v * sizeof(struct List));

    for (int i = 0; i < v; i++)
        g->arr[i].head = NULL;

    return g;
}

void addEdge(GRAPH g, int src, int dest)
{
    NODE newNode = newAdjNode(dest);
    newNode->next = g->arr[src].head;
    g->arr[src].head = newNode;

    newNode = newAdjNode(src);
    newNode->next = g->arr[dest].head;
    g->arr[dest].head = newNode;
}

void display(GRAPH g)
{
    for (int i = 0; i < g->numVertices; i++)
    {
        NODE curr = g->arr[i].head;
        printf("Adjacency list of vertex %d: head", i);
        while (curr)
        {
            printf(" -> %d", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }
}

void freeGraph(GRAPH g)
{
    if (!g) return;

    for (int v = 0; v < g->numVertices; v++)
    {
        NODE curr = g->arr[v].head;
        while (curr)
        {
            NODE temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(g->arr);
    free(g);
}

int main()
{
    GRAPH g = createGraph(5);

    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    display(g);
    freeGraph(g);
    return 0;
}
