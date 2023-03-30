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

#define V  7
void dfs_util(int node,int graph[V][V],bool vis[]) {
    cout << node << " ";
    vis[node] = true;

    for(int j = 0; j < V; j++) {
        if(graph[node][j] == 1 && !vis[j]) {
            dfs_util(j,graph,vis);
        }
    }
}
void DFS(int graph[V][V]) {
    bool vis[V] = {false};

    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            dfs_util(i,graph,vis);
        }
    }
}

void bfs_util(int node,int graph[V][V],bool vis[]) {
    queue<int> q;

    q.push(0);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(!vis[curr]) {
            cout << curr << " ";
            vis[curr] = true;

            for(int j = 0; j < V; j++) {
                if(graph[curr][j] == 1 && !vis[j]) {
                    q.push(j);
                }
            }
        }
    }
}
void BFS(int graph[V][V]) {
    bool vis[V] = {false};

    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            bfs_util(i,graph,vis);
        }
    }
}


int main()
{
    // int v;
    // cout << "Enter the number of nodes/vertices in graph" << endl;
    // cin >> v;

    int graph[V][V];

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
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
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "BFS Traversal" << endl;
    BFS(graph);


    return 0;
}