void DFS(int graph[MAX][MAX], bool visited[],int node,int numNodes)
{
    visited[node] = true;
    printf("%d ", node);
    for(int i=0;i<numNodes;i++)
    {
        if(graph[node][i] == 1 && !visited[i])
        {
            DFS(graph, visited, i, numNodes);
        }
    }
} 