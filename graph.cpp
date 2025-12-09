#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> createGraph(int v, vector<vector<int>> &edge)
{
    vector<vector<int>> mat(v, vector<int>(v, 0));

    for(auto &it : edge){
        int u = it[0];
        int V = it[1];
        mat[u][V] = 1;
        mat[V][u] = 1;
    }

    return mat;
}

int main()
{

    int v = 3;
    vector<vector<int>> edge = {{0, 1}, {1, 2}, {0, 2}};
    vector<vector<int>> mat = createGraph(v, edge);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}