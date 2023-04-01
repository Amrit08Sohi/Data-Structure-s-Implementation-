#include <bits/stdc++.h>
using namespace std;
#define V 5

/*
    Given directed graph

    0 ------> 1 <-- 4
   /|\        |    /|\
    |         |    /
    |        \|/ /
    3 ------> 2


Adjacency Matrix : {0,1,0,0,0}
                   {0,0,1,0,0}
                   {0,0,0,0,1}
                   {1,0,1,0,0}
                   {0,1,0,0,0}

Path Matrix :    {0,1,1,0,1}
                 {0,1,1,0,1}
                 {0,1,1,0,1}
                 {1,1,1,0,1}
                 {0,1,1,0,1}

*/

//  Warshall's Algorithm : Time Complexity : O(N^3)
void build_Path_matrix(int path[][V])
{

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                path[i][j] = path[i][j] or path[i][k] and path[k][j];
            }
        }
    }
}

int main()
{
    int graph[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            char ch;
            cout << "(y/n)Do you want to add an edge between " << i << "-->" << j << endl;
            cin >> ch;
            if (ch == 'y')
            {
                graph[i][j] = 1;
            }
            else
            {
                graph[i][j] = 0;
            }
        }
    }
    cout << "Graph Using Adjacency Matrix" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int path[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            path[i][j] = graph[i][j];
        }
    }

    build_Path_matrix(path);
    cout << "Path Matrix" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}