/* 최단거리 알고리즘 벨만포드(BellmanFord)

가중치가 각자 다르고 음수가중치가 있을 때, 음의 가중치 존재유무도 판단 가능
*/

#include <vector>
#include <iostream>

#define INF 2147483647

class Edge {
public:
	int from;
	int to;
	int cost;

	Edge(int f, int t, int c) {
		from = f;
		to = t;
		cost = c;
	}
};

std::vector<Edge> edges;
std::vector<int> distance;

void Bellman_Ford(int nov)
{
	distance[1] = 0;
	for (int i = 0; i < nov - 1; i++) // (vertex의 갯수 - 1)회 반복
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int From = edges[j].from;
			int To = edges[j].to;
			int Cost = edges[j].cost;

			if (distance[From] == INF) continue; // 시작점이 계산된적 없다면 넘기고
			if (distance[To] > distance[From] + Cost) distance[To] = distance[From] + Cost; // 갱신
		}
	}

	// 음의 사이클이 존재하는지 확인해보기
	for (int i = 0; i < edges.size(); i++)
	{
		int From = edges[i].from;
		int To = edges[i].to;
		int Cost = edges[i].cost;

		if (distance[From] == INF) continue;
		if (distance[To] > distance[From] + Cost) { // 비용이 더 줄어서 갱신되고있다면
			std::cout << "음의 사이클이 존재\n";
			return;
		}
	}

	std::cout << "음의 사이클이 존재하지 않음.\n";
	for (int i = 1; i < distance.size(); i++) {
		std::cout << "시작점부터 " << i << "노드까지의 거리 : " << distance[i] << '\n';
	}
}

int main()
{
	int number_of_vertex, number_of_edge, start_vertex;
	std::cin >> number_of_vertex >> number_of_edge >> start_vertex;

	distance.resize(number_of_vertex + 1, INF); // 전부 INF로 초기화

	for (int i = 0; i < number_of_edge; i++) {
		int from, to, cost;
		std::cin >> from >> to >> cost;
		edges.push_back(Edge(from, to, cost));
	}

	Bellman_Ford(number_of_vertex);

	return 0;
}