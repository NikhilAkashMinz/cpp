#include<stdio.h>
#include<stdlib.h>


typedef struct Graph{
    int V;
    int **adj;

}*Graph;

Graph createGrap(int v)
{
    Graph graph = (Graph)malloc(sizeof(struct Graph));
    graph->V = v;

    graph->adj = (int **)malloc(v * sizeof(int *));
    for(int i=0;i<v;i++){
        graph->adj[i] = (int *)malloc(v * sizeof(int));
        for(int j=0;j<v;j++){
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph graph, int s, int d)
{
    graph->adj[s][d] = 1;
    graph->adj[d][s] = 1;
}

void PrintGraph(Graph graph)
{
    for(int i=0;i<graph->V;i++){
        for(int j=0;j<graph->V;j++){
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph graph)
{
    for(int i=0;i<graph->V;i++){
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);
    printf("Graph memory freed\n");
}

int main(){
    Graph graph = createGrap(3);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 0, 2);
    PrintGraph(graph);
    freeGraph(graph);
    PrintGraph(graph); 
    return 0;
}