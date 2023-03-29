#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int src;
        int dest;
        int wt;

        Edge(int s,int d,int w) {
            src = s;
            dest = d;
            wt = w;
        }

        void print() {
            cout << "SOURCE : " << src << ", Destination : " << dest << ", Weight : " << wt << endl; 
        }
};
/*
Graph to Build
          (5)
       0-------1
             /  \
       (1) /     \ (3)   
          2-------3
     (7)  |   (2)
          |
          4 

*/



void DFS_Util(int node,vector<Edge> graph[],vector<bool> &visited) { //  Time Complexity : O(V+E)
    // First, Print the node and mark it visited
    cout << node << " ";
    visited[node] = true;
    // Call for neighbouring nodes if they are not visited
    for(int i = 0; i < graph[node].size(); i++) {
        Edge e = graph[node][i];
        if(!visited[e.dest]) {
            DFS_Util(e.dest,graph,visited);
        }
    }
}

// if our graph is divided into more than one components then we travel it using this.
void DFS(vector<Edge> graph[],int V) {
    vector<bool> visited(V,false);
    for(int i = 0 ; i < V; i++) {
        if(!visited[i]) {
            DFS_Util(i,graph,visited);
        }
    }
}
void BFS_Util(int node,vector<Edge> graph[],vector<bool> &vis) { //  Time Complexity : O(V+E)
    queue<int> q;
    // Add source node to your queue
    q.push(0);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(!vis[curr]) {
            // First, Print the node and mark it visited
            cout << curr << " ";
            vis[curr] = true;

            // Add its neighbours to queue
            for(int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr][i];
                q.push(e.dest);
            }
         }
    }
}
void BFS(vector<Edge> graph[],int V) {
    vector<bool> visited(V,false);
    for(int i = 0 ; i < V; i++) {
        if(!visited[i]) {
            BFS_Util(i,graph,visited);
        }
    }
}



void addEdge(vector<Edge> graph[],int src,int dest,int wt) {
    Edge e(src,dest,wt);
    graph[src].push_back(e);
}
int main()
{
    int V;
    cout << "Enter number of vertices(Nodes) in graph" << endl;
    cin >> V;
    vector<Edge> graph[V];

    addEdge(graph,0,1,5);
    addEdge(graph,1,0,5);
    addEdge(graph,1,2,1);
    addEdge(graph,1,3,3);
    addEdge(graph,2,1,1);
    addEdge(graph,2,3,2);
    addEdge(graph,2,4,7);
    addEdge(graph,3,1,3);
    addEdge(graph,3,2,2);
    addEdge(graph,4,2,7);

    cout << "BFS Traversal of graph" << endl;
    BFS(graph,V);
    cout << endl;
    // To get neighbour of dest of any vertex
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            Edge e = graph[i][j];
            e.print();
        }
    }

    




    return 0;
}