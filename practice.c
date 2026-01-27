#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numVerticies;
    int **adjMatrix;
}*GRAPH;

GRAPH createGraph(int verticies)
{
    GRAPH graph = malloc(sizeof(*graph));
    graph->numVerticies = verticies;
    graph->adjMatrix = malloc(verticies * sizeof(int *));   
    for (int i = 0; i < verticies; i++) {
        graph->adjMatrix[i] = malloc(verticies* sizeof(int));
        for (int j = 0; j < verticies; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(GRAPH graph,int src,int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void Display(GRAPH graph)
{
    for(int i = 0; i<graph->numVerticies; i++)
    {
        for(int j = 0; j<graph->numVerticies; j++)
        {
            printf("%d ",graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(GRAPH graph)
{
    for (int i = 0; i < graph->numVerticies; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

void dfs(GRAPH graph,int visited[],int node, int numNodes)
{
    visited[node]=1;
    printf("%d ",node);

    for(int i=0;i<numNodes;i++)
    {
        if(graph->adjMatrix[node][i]==1 && !visited[i])
        {
            dfs(graph,visited,i,numNodes);
        }
    }
}

int main()
{
    GRAPH graph = createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,4);
    addEdge(graph,1,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);

    Display(graph);

    int visited[5] = {0};

    printf("\nDFS Traversal starting from node 0:\n");
    dfs(graph, visited, 0, 5);
    freeGraph(graph);
    return 0;
}

// typedef struct AdjNode {
//     int dest;
//     struct AdjNode* next;
// } *NODE;

// typedef struct Adj {
//     NODE head;
// } AdjList;

// typedef struct myGraph {
//     int numVerticies;
//     AdjList* array;
// } *GRAPH;

// NODE newAdjNode(int dest)
// {
//     NODE newNode = (NODE)malloc(sizeof(struct AdjNode));
//     if (!newNode) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }
//     newNode->dest = dest;
//     newNode->next = NULL;
//     return newNode;
// }

// GRAPH createGraph(int vert)
// {
//     GRAPH graph = (GRAPH)malloc(sizeof(struct myGraph));
//     if (!graph) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }

//     graph->numVerticies = vert;
//     graph->array = (AdjList*)malloc(vert * sizeof(AdjList));
//     if (!graph->array) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }

//     for (int i = 0; i < vert; i++) {
//         graph->array[i].head = NULL;
//     }

//     return graph;
// }

// void addEdge(GRAPH graph, int src, int dest)
// {
//     NODE newNode = newAdjNode(dest);
//     newNode->next = graph->array[src].head;
//     graph->array[src].head = newNode;

//     newNode = newAdjNode(src);
//     newNode->next = graph->array[dest].head;
//     graph->array[dest].head = newNode;
// }

// void Display(GRAPH graph)
// {
//     for (int v = 0; v < graph->numVerticies; v++) {
//         NODE currNode = graph->array[v].head;
//         printf("Adjacency list of vertex %d\n head", v);
//         while (currNode) {
//             printf(" -> %d", currNode->dest);
//             currNode = currNode->next;
//         }
//         printf("\n");
//     }
// }

// void freeGraph(GRAPH graph)
// {
//     if (!graph) return;

//     for (int i = 0; i < graph->numVerticies; i++) {
//         NODE head = graph->array[i].head;
//         while (head) {
//             NODE temp = head;
//             head = head->next;
//             free(temp);
//         }
//     }

//     free(graph->array);
//     free(graph);
// }

// int main()
// {
//     GRAPH graph = createGraph(5);

//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 4);
//     addEdge(graph, 1, 4);
//     addEdge(graph, 1, 3);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 2, 3);
//     addEdge(graph, 3, 4);

//     Display(graph);
//     freeGraph(graph);

//     return 0;
// }