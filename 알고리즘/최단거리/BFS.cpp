/* 최단거리 알고리즘 BFS

가중치가 없거나 모두 같을 때
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> adj; // 그래프의 인접 리스트 표현
std::vector<int> distance; // 각 정점의 최단거리
std::vector<int> parent; // 최단경로를 기록하기 위해

void bfs(int start)
{
	distance[start] = 0; // 시작점은 자기 자신이니 거리가 0
	std::queue<int> q;
	q.push(start);

	while (q.size()) {
		int here = q.front();
		q.pop();
		for (int there : adj[here]) {
			if (distance[there] == -1) {
				q.push(there);
				distance[there] = distance[here] + 1; // 가중치 있으면 1대신 가중치
				parent[there] = here; // 부모에 대한 정보를 추가
			}
		}
	}
}

std::vector<int> shortestPath(int v) // v까지의 최단 경로 func
{
	std::vector<int> path;
	path.push_back(v); // 자기자신 넣고 시작

	while (parent[v] != -1) {
		v = parent[v];
		path.push_back(v);
	}
	reverse(path.begin(), path.end()); // 자식노드부터 부모노드순으로 올라갔으니 역순으로 정리
	return path;
}

int main()
{
	int number_of_vertex, number_of_edge, start_vertex;
	std::cin >> number_of_vertex >> number_of_edge >> start_vertex;

	// 이 세줄에서 nov+1하는 이유는 보통 정점을 1번부터 세기때문
	// 만약 0번부터 센다면 그냥 +1 안해도 됨
	distance.resize(number_of_vertex + 1, -1);	// 전부 -1로 초기화
	adj.resize(number_of_vertex + 1);
	parent.resize(number_of_vertex + 1, -1);

	int u, v;
	for (int i = 0; i < number_of_edge; i++) {
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(start_vertex);

	// 최단 경로 출력하기
	std::vector<int> sp;
	std::cout << "찾고자 하는 노드 number : ";

	int look_for;
	std::cin >> look_for;
	sp = shortestPath(look_for);
	for (int i : sp) {
		std::cout << i << ' ';
	}

	return 0;
}