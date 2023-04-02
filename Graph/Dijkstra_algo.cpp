#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int dest;
    int wt;

    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }

    void print()
    {
        cout << "SOURCE : " << src << ", Destination : " << dest << ", Weight : " << wt << endl;
    }
};

class Pair
{
public:
    int node, path;
    Pair(int n, int p)
    {
        node = n;
        path = p;
    }
};

class Comparator
{
public:
    bool operator()(Pair p1, Pair p2)
    {
        return p1.path >= p2.path;
    }
};

void dijkstra(vector<Edge> graph[], int src,int V)
{
    int dist[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (i != src)
        {
            dist[i] = INT_MAX;
        }
    }
    bool vis[V] = {false};

    priority_queue<Pair, vector<Pair>, Comparator> pq;

    pq.push(Pair(src, 0));

    while (!pq.empty())
    {
        Pair currPair = pq.top();
        pq.pop();
        if (!vis[currPair.node])
        {
            vis[currPair.node] = true;

            // neighbours of curr node
            for (int i = 0; i < graph[currPair.node].size(); i++)
            {
                Edge e = graph[currPair.node][i];
                int u = e.src;  // source
                int v = e.dest; // destination
                int wt = e.wt;

                if (dist[u] + wt < dist[v])
                { // update distance of src to v
                    dist[v] = dist[u] + wt;
                    pq.push(Pair(v, dist[v]));
                }
            }
        }
    }

    for(int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }
}
int main()
{
    int V;
    cout << "Enter number of vertices(Nodes) in graph" << endl;
    cin >> V;
    vector<Edge> graph[V];

    graph[0].push_back(Edge(0,1,2));
    graph[0].push_back(Edge(0,2,4));

    graph[1].push_back(Edge(1,2,1));
    graph[1].push_back(Edge(1,3,7));

    graph[2].push_back(Edge(2,4,3));

    graph[3].push_back(Edge(3,5,1));

    graph[4].push_back(Edge(4,3,2));
    graph[4].push_back(Edge(4,5,5));


    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            Edge e = graph[i][j];
            e.print();
        }
    }
    dijkstra(graph,0,V);
    return 0;
}