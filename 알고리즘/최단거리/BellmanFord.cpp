/* �ִܰŸ� �˰��� ��������(BellmanFord)

����ġ�� ���� �ٸ��� ��������ġ�� ���� ��, ���� ����ġ ���������� �Ǵ� ����
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
	for (int i = 0; i < nov - 1; i++) // (vertex�� ���� - 1)ȸ �ݺ�
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int From = edges[j].from;
			int To = edges[j].to;
			int Cost = edges[j].cost;

			if (distance[From] == INF) continue; // �������� ������ ���ٸ� �ѱ��
			if (distance[To] > distance[From] + Cost) distance[To] = distance[From] + Cost; // ����
		}
	}

	// ���� ����Ŭ�� �����ϴ��� Ȯ���غ���
	for (int i = 0; i < edges.size(); i++)
	{
		int From = edges[i].from;
		int To = edges[i].to;
		int Cost = edges[i].cost;

		if (distance[From] == INF) continue;
		if (distance[To] > distance[From] + Cost) { // ����� �� �پ ���ŵǰ��ִٸ�
			std::cout << "���� ����Ŭ�� ����\n";
			return;
		}
	}

	std::cout << "���� ����Ŭ�� �������� ����.\n";
	for (int i = 1; i < distance.size(); i++) {
		std::cout << "���������� " << i << "�������� �Ÿ� : " << distance[i] << '\n';
	}
}

int main()
{
	int number_of_vertex, number_of_edge, start_vertex;
	std::cin >> number_of_vertex >> number_of_edge >> start_vertex;

	distance.resize(number_of_vertex + 1, INF); // ���� INF�� �ʱ�ȭ

	for (int i = 0; i < number_of_edge; i++) {
		int from, to, cost;
		std::cin >> from >> to >> cost;
		edges.push_back(Edge(from, to, cost));
	}

	Bellman_Ford(number_of_vertex);

	return 0;
}