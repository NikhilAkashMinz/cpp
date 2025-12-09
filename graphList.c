#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode {
    int dest;
    struct AdjNode* next;
}* Node;

typedef struct AdjList {
    Node head;
}* List;

typedef struct myGraph {
    int vertices;
    List array;
}* Graph;

Node AddNode(int dest)
{
    Node newNode = (Node)malloc(sizeof(struct AdjNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph CreateGraph(int v)
{
    Graph graph = (Graph)malloc(sizeof(struct myGraph));
    graph->vertices = v;

    graph->array = (List)malloc(v * sizeof(struct AdjList));

    for (int i = 0; i < graph->vertices; i++)
        graph->array[i].head = NULL;

    return graph;
}

void AddEdge(Graph graph, int src, int dest)
{
    Node newNode = AddNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    Node newNode2 = AddNode(src);
    newNode2->next = graph->array[dest].head;
    graph->array[dest].head = newNode2;
}

void Display(Graph graph)
{
    for (int v = 0; v < graph->vertices; v++)
    {
        Node temp = graph->array[v].head;
        printf("Adjacency of vertex %d\nhead", v);

        while (temp)
        {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

void freeGraph(Graph graph)
{
    if (graph)
    {
        for (int v = 0; v < graph->vertices; v++)
        {
            Node head = graph->array[v].head;
            while (head)
            {
                Node temp = head;
                head = head->next;
                free(temp);
            }
        }
        free(graph->array);
        free(graph);
    }
}

int main()
{
    int V = 5;
    Graph graph = CreateGraph(V);

    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 4);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);

    Display(graph);
    freeGraph(graph);

    return 0;
}
