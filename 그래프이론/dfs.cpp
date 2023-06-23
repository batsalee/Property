#include <iostream>
#include <vector>

std::vector<bool> visited;
std::vector<std::vector<int>> adj;

void dfs(int u)
{
	visited[u] = true;
	std::cout << u << ' ';

	for (int v : adj[u]) {
		if (!visited[v]) dfs(v);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int number_of_vertex, number_of_edge, start_vertex;
	std::cin >> number_of_vertex >> number_of_edge >> start_vertex;

	visited.resize(number_of_vertex + 1);
	adj.resize(number_of_vertex + 1);

	int u, v;
	for (int i = 0; i < number_of_edge; i++) {
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(start_vertex);

	return 0;
}