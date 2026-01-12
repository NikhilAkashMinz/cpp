#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

void dfs(int graph[MAX][MAX],bool visted[],int node,int numNode)
{
    visted[node] = true;
    printf("%d ",node);

    for(int neighbor = 0; neighbor < numNode;neighbor++)
    {
        if(graph[node][neighbor] == 1 && !visted[neighbor])
        {
            dfs(graph,visted,neighbor,numNode);
        }
    }
}

int main()
{
    int numNode;
    int graph[MAX][MAX];
    bool visited[MAX] = {false};
    int startNode;

    printf("Enter number of nodes: ");
    scanf("%d",&numNode);

    printf("Enter adjacency matrix \n");
    for(int i = 0; i<numNode; i++)
    {
        for(int j = 0; j < numNode; j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter starting Node: ");
    scanf("%d", &startNode);

    printf("Dfs Traversal: ");
    dfs(graph,visited,startNode,numNode);

    return 0;
}