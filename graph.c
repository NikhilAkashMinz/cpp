#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int numVerticies;
    int **adjMatric;
}* Graph;

Graph createGraph(int verticies)
{
    Graph  graph = malloc(sizeof(Graph));
    graph->numVerticies = verticies;

    graph->adjMatric = malloc(verticies*sizeof(int *));
    for(int i = 0;i<verticies;i++)
    {
        graph->adjMatric[i] = malloc(verticies*sizeof(int*));
        for(int j = 0;j<verticies;j++)
        {
            graph->adjMatric[i][j] = 0;
        }
    }
    return graph;
}

void addEdges(Graph graph,int src, int dest)
{
    graph->adjMatric[src][dest] = 1;
    graph->adjMatric[dest][src] = 1;
}

void display(Graph graph)
{
    for(int i = 0; i<graph->numVerticies;i++)
    {
        for(int j = 0; j<graph->numVerticies;j++)
        {
            printf("%d ", graph->adjMatric[i][j]);
        }
        printf("\n");

    }
}

void freeGraph(Graph graph)
{
    for(int i=0; i<graph->numVerticies;i++)
    {
        free(graph->adjMatric[i]);
    }
    free(graph->adjMatric);
    free(graph);
}

int main()
{
    int verticies = 4;
    Graph graph = createGraph(verticies);
    addEdges(graph , 0 , 1);
    addEdges(graph , 1, 2);
    addEdges(graph , 2, 3);
    display(graph);
    freeGraph(graph);
    return 0;
}