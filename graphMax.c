#include<stdlib.h>
#include<stdio.h>

typedef struct graph{
    int numVertices;
    int **adjMatrix;
} *GRAPH;


GRAPH createGraph(int numVer)
{
     GRAPH g = (GRAPH)malloc(sizeof(struct graph));
    g->numVertices = numVer;
    g->adjMatrix = (int **)malloc(numVer * sizeof(int *));

    for(int i = 0; i < numVer; i++)
    {
        g->adjMatrix[i] = (int*)malloc(numVer * sizeof(int));
        for(int j = 0; j < numVer; j++)
        {
            g->adjMatrix[i][j] = 0;
        }
    }
    return g;
}


void addEdge(GRAPH g, int src, int dest)
{
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}


void display(GRAPH g)
{
    for(int i=0;i<g->numVertices;i++)
    {
        for(int j=0;j<g->numVertices;j++)
        {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(GRAPH g)
{
    for(int i = 0; i < g->numVertices; i++)
    {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g);
}

int main()
{
    int numVertices = 5;
    GRAPH g = createGraph(numVertices);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);

    printf("Adjacency Matrix:\n");
    display(g);

    freeGraph(g);
    return 0;
} 