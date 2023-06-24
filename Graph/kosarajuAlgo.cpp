#include<bits/stdc++.h>
using namespace std;
/**
 * The function performs a topological sort on a given directed graph using recursion and a stack.
 * 
 * @param graph A vector array representing the graph where each index represents a vertex and the
 * vector at that index contains the vertices that the index vertex has an outgoing edge to.
 * @param curr curr is the current node being visited in the topological sort algorithm.
 * @param vis A boolean array that keeps track of whether a node has been visited or not during the
 * topological sort algorithm.
 * @param st `st` is a reference to a stack of integers. This stack is used to store the nodes in the
 * topological order as they are visited during the depth-first search traversal of the graph. The
 * nodes are pushed onto the stack in the order in which they finish their recursive DFS calls.
 */
void topSort(vector<int> graph[],int curr,bool *vis,stack<int> &st) {
    vis[curr] = true;

    for(int i = 0; i < graph[curr].size(); i++) {
        if(!vis[graph[curr][i]]) {
            topSort(graph,graph[curr][i],vis,st);
        }
    }
    st.push(curr);
}
/**
 * The function performs a depth-first search on a given graph represented by its transpose and marks
 * visited nodes.
 * 
 * @param transpose The transpose parameter is a vector of adjacency lists representing the transpose
 * of a graph. In other words, if the original graph had an edge from vertex u to vertex v, then the
 * transpose graph would have an edge from vertex v to vertex u.
 * @param curr curr is an integer variable that represents the current node being visited during the
 * depth-first search traversal.
 * @param vis vis is a boolean array that keeps track of whether a node has been visited or not during
 * the depth-first search traversal. It is used to avoid visiting the same node multiple times and to
 * prevent infinite loops in the graph.
 */
void dfs(vector<int> transpose[],int curr,bool *vis) {
	vis[curr] = true;
    cout << curr << " ";
	for(int i = 0; i < transpose[curr].size(); i++) {
		if(!vis[transpose[curr][i]]) {
			dfs(transpose,transpose[curr][i],vis);
		}
	}
}
/**
 * The function calculates the number of strongly connected components in a directed graph using
 * Kosaraju's algorithm.
 * 
 * @param v The number of vertices in the graph.
 * @param edges A vector of vectors representing the edges of a directed graph. Each inner vector
 * contains two integers representing an edge from the first integer to the second integer.
 * 
 * @return the number of strongly connected components in the given graph.
 */
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
    /* This code block is creating an adjacency list representation of a directed graph using the given
	edges. It initializes a stack to store the vertices in topological order, a boolean array to
	keep track of visited vertices, and a vector of vectors to represent the graph. It then loops
	through the edges and adds the second vertex of each edge to the adjacency list of the first
	vertex. */
	stack<int> st;
	bool vis[v] = {false};
	vector<int> graph[v];
	for(int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back(edges[i][1]);
	}

	/* This `for` loop is iterating through all the vertices of the graph and calling the `topSort`
	function for each unvisited vertex. The `topSort` function performs a depth-first search on the
	graph and adds the vertices to a stack in topological order. By calling `topSort` for each
	unvisited vertex, the loop ensures that all vertices are visited and added to the stack in
	topological order. */
	for(int i = 0; i < v; i++) {
		if(!vis[i]) {
			topSort(graph,i,vis,st);
		}
	}
	/* This code block is creating the transpose of the given directed graph. The transpose of a graph is
	a new graph that has all the edges of the original graph reversed. In other words, if the original
	graph had an edge from vertex u to vertex v, then the transpose graph would have an edge from
	vertex v to vertex u. */
	vector<int> transpose[v];
	for(int i = 0; i < edges.size(); i++) {
		transpose[edges[i][1]].push_back(edges[i][0]);
	}

/* This code block is implementing Kosaraju's algorithm to find the strongly connected components of a
directed graph. */
	bool visited[v] = {false};
	int ans = 0;
	while(!st.empty()) {
		int curr = st.top();
		st.pop();
		if(!visited[curr]) {
            cout << "Strongly Connected Component : " ;
			dfs(transpose,curr,visited);
            cout << endl;
			ans++;
		}
	}
	return ans;


}

int main()
{

    vector<vector<int>> edges = {{2,3},{3,1},{4,0},{4,1},{5,0},{5,2}};
   

    cout << stronglyConnectedComponents(6,edges);
    /*
        2   3
        3   1
        4   0,1
        5   0,2
    */
    return 0;
}