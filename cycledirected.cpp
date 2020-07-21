// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &recst, int source, int parent)
{
	visited[source] = true;
	recst[source] = true;
	for (auto child : adj[source])
	{
		if (!visited[child])
		{
			if (dfs(adj, visited, recst, child, source) == true)
			{
				return true;
			}
		}
		else
		{
			if (recst[child] == true)
				return true;
		}
	}
	recst[source] = false;
	return false;
}

bool isCyclic(int V, vector<int> adj[])
{
	vector<bool> visited(V, false);
	vector<bool> recst(V, false);
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			if (dfs(adj, visited, recst, i, -1) == true)
				return true;
		}
	}
	return false;
}

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
	freopen("builds/input.txt", "r", stdin);
	freopen("builds/output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--)
	{

		int v, e;
		cin >> v >> e;

		vector<int> adj[v];

		for (int i = 0; i < e; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		cout << isCyclic(v, adj) << endl;
	}

	return 0;
} // } Driver Code Ends