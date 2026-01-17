#include<stdio.h>
#include<stdlib.h>

typedef struct AdjNode{
    int dest;
    struct AdjNode* next;
}*NODE;

typedef struct Adj{
    NODE head; 
}*LIST;

typedef struct myGraph{
    int numVerticies;
    LIST array;
}*Graph;

NODE newAdjNode(int dest)
{
    NODE newNode = (NODE)malloc(sizeof(struct AdjNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph createGraph(int V)
{
    Graph graph = (Graph)malloc(sizeof(struct myGraph));
    graph->numVerticies = V;

    graph->array = (LIST)malloc(V* sizeof(struct Adj));

    for(int i = 0; i<V;i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph graph, int src, int dest)
{
    NODE newNode =  newAdjNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void Display(Graph graph)
{
    for(int v=0;v<graph->numVerticies;v++)
    {
        NODE curr = graph->array[v].head;
        printf("\nAdjcecny list of vertext %d \n head ", v);

        while(curr)
        {
            printf("-> %d", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }

}

void freeGraph(Graph graph)
{
    if (graph)
    {
        if (graph->array)
        {
            for (int v = 0; v < graph->numVerticies; v++)
            {
                NODE head = graph->array[v].head;
                NODE temp;

                while (head)
                {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
            }
            free(graph->array);
        }
        free(graph);
    }
}

int main()
{
    int V = 3;

    Graph graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);

    Display(graph);

    freeGraph(graph);

    return 0;
}

