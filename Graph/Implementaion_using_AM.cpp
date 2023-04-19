#include<bits/stdc++.h>
using namespace std;
/*
        Graph to created
                    1----3
                  /      | \
                 0       |  5----6
                  \      | / 
                   2-----4

    Adjacency matrix : 
        0  1  2  3  4  5  6
     0  0  1  1  0  0  0  0
     1  1  0  0  1  0  0  0
     2  1  0  0  0  1  0  0
     3  0  1  0  0  1  1  0
     4  0  0  1  1  0  1  0 
     5  0  0  0  1  1  0  1 
     6  0  0  0  0  0  1  0             
*/

void dfs_util(int node,int **graph,bool vis[],int v) {
    cout << node << " ";
    vis[node] = true;

    for(int j = 0; j < v; j++) {
        if(graph[node][j] == 1 && !vis[j]) {
            dfs_util(j,graph,vis,v);
        }
    }
}
void DFS(int **graph,int v) {
    bool vis[v] = {false};

    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            dfs_util(i,graph,vis,v);
        }
    }
}

void bfs_util(int node,int **graph,bool vis[],int v) {
    queue<int> q;

    q.push(0);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(!vis[curr]) {
            cout << curr << " ";
            vis[curr] = true;

            for(int j = 0; j < v; j++) {
                if(graph[curr][j] == 1 && !vis[j]) {
                    q.push(j);
                }
            }
        }
    }
}
void BFS(int **graph,int v) {
    bool vis[v] = {false};

    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            bfs_util(i,graph,vis,v);
        }
    }
}


int main()
{
    int v;
    cout << "Enter the number of nodes/vertices in graph" << endl;
    cin >> v;

    int **graph;

    graph = new int*[v];
    for(int i = 0; i < v; i++) {
        graph[i] = new int[v];
    }


    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            char ch;
            cout << "(y/n)Do you want to add an edge between " << i << "-->" << j << endl;
            cin >> ch;
            if(ch=='y') {
                graph[i][j] = 1;
            }else{
                graph[i][j] = 0;
            }
        }
    }

    cout << "Graph Using Adjacency Matrix" << endl;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "BFS Traversal" << endl;
    BFS(graph,v);

    for(int i = 0; i < v; i++) {
        delete[] graph[i];
    }
    delete[] graph;



    return 0;
}