#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int> graph[],int node,int dist,vector<int> &dp,vector<bool> &vis) {
    /* This code is performing a depth-first search (DFS) traversal of a graph starting from a given
    node `node`. It sets the `vis[node]` boolean value to `true` to mark the current node as visited
    and sets the `dp[node]` value to `dist`, which represents the distance of the current node from
    the starting node. It then iterates over the neighbors of the current node using a `for` loop
    and checks if the neighbor has not been visited before (`!vis[graph[node][i]]`). If the neighbor
    has not been visited, it recursively calls the `DFS` function with the neighbor node, `dist+1`
    (which represents the distance of the neighbor node from the starting node), the `dp` vector,
    and the `vis` vector as parameters. This process continues until all nodes reachable from the
    starting node have been visited and their distances have been calculated and stored in the `dp`
    vector. */
    vis[node] = true;
    dp[node] = dist;
    for(int i = 0; i < graph[node].size(); i++) {
        if(!vis[graph[node][i]]) {
            DFS(graph,graph[node][i],dist+1,dp,vis);
        }
    }
}
/**
 * The function takes in a graph represented by a vector of edges and returns a vector of integers
 * representing the sum of distances of each node from all other nodes in the graph.
 * 
 * @param edges A vector of vectors representing the edges of the graph. Each inner vector contains two
 * integers representing the nodes connected by the edge.
 * @param n The number of nodes in the graph.
 * 
 * @return a vector of integers `ans`, where each element represents the sum of distances of all nodes
 * from a particular node in an undirected graph.
 */
vector<int> sumofDistance(vector<vector<int>> &edges, int n)
{
    // Write your code here.
    /* This code is creating an undirected graph using an adjacency list representation. It initializes
    an integer variable `N` with the value of `n`, which is the number of nodes in the graph. It
    then creates a vector of `N` elements, where each element is a vector of integers representing
    the neighbors of a node. The `for` loop iterates over the edges of the graph and adds the edges
    to the adjacency list by pushing the adjacent nodes to each other's vector. This creates an
    undirected graph where each node is represented by an index in the vector and its neighbors are
    stored in its corresponding vector. */
    int N = n;
    vector<int> graph[N];
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    } 
    //vector<bool> vis = {false};
    vector<int> ans;
    /* This `for` loop is iterating over all the nodes in the graph and performing the following steps
    for each node:
    1. Initializing a vector `dp` of size `N` with all elements as 0. This vector will store the
    distance of each node from the current node.
    2. Initializing a vector `vis` of size `N` with all elements as false. This vector will keep
    track of whether a node has been visited or not during the DFS traversal.
    3. Calling the `DFS` function with the current node, distance 0, `dp` vector, and `vis` vector
    as parameters. This will perform a DFS traversal of the graph starting from the current node and
    update the `dp` vector with the distance of each node from the current node.
    4. Calculating the sum of distances of all nodes from the current node by iterating over the
    `dp` vector and adding up all the distances.
    5. Pushing the sum of distances to the `ans` vector, which will store the answer for each node. */
    for(int i = 0; i < N; i++) {
        vector<int> dp(N,0);
        vector<bool> vis(N,false);
        DFS(graph,i,0,dp,vis);
        int sum = 0;
        for(int j = 0; j < N; j++) {
            sum += dp[j];
        }
        ans.push_back(sum);
    }
    return ans;
}
int main()
{
    vector<vector<int>> edges = {{0,4},{3,1},{3,2},{0,3}};
    int n = 5;
    vector<int> ans = sumofDistance(edges,n);
    for(int ele : ans) {
        cout << ele << " ";
    }
   
    return 0;
}