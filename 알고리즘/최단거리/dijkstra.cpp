/* �ִܰŸ� �˰��� ���ͽ�Ʈ��(dijkstra)

����ġ�� ���� �ٸ��� ��� ����� ��
*/

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147483647

std::vector<std::vector<std::pair<int, int>>> adj;
std::vector<int> distance;
std::vector<int> parent;

std::vector<int> dijkstra(int start) {
	std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<> > pq;
	// (����ġ������ distance, ����ġ) ���·� ����

	distance[start] = 0;				// ���������� �Ÿ��� 0
	pq.push(std::make_pair(0, start));	// (����ġ������ distance, ����ġ)

	while (!pq.empty()) {
		int cost = pq.top().first;		// �湮�� ������ dist �� 
		int here = pq.top().second;		// ���� �湮�� ���� 
		pq.pop();
		if (distance[here] < cost) continue; // ���� ���� ������ �����ؾ��ϴ� �������� Ȯ��

		for (int i = 0; i < adj[here].size(); i++) {    // ���� �湮�� ������ �ֺ� ���� ��� ���� 
			int there = adj[here][i].second;			// ������ ���� ���� 
			int thereCost = cost + adj[here][i].first;	// ���� �湮�� ������ ���ļ� ���� ������ ������ ��� 
			if (thereCost < distance[there]) {			// ���� ��뺸�� ���� �湮�� ������ ��ģ ����� �� �δٸ� 
				distance[there] = thereCost;			// ���� 
				pq.push(std::make_pair(thereCost, there));	// pq�� ���� 
				parent[there] = here;
			}
		}
	}

	return distance;
}

std::vector<int> shortestPath(int v)
{
	std::vector<int> path;
	path.push_back(v); // �ڱ��ڽ� �ְ� ����

	while (parent[v] != -1) {
		v = parent[v];
		path.push_back(v);
	}
	reverse(path.begin(), path.end());
	return path;
}

int main()
{
	int number_of_vertex, number_of_edge, start_vertex;
	std::cin >> number_of_vertex >> number_of_edge >> start_vertex;

	// �� ���ٿ��� nov+1�ϴ� ������ ���� ������ 1������ ���⶧��
	// ���� 0������ ���ٸ� �׳� +1 ���ص� ��
	distance.resize(number_of_vertex, INF); // ���� INF�� �ʱ�ȭ
	adj.resize(number_of_vertex + 1);
	parent.resize(number_of_vertex, -1);

	for (int i = 0; i < number_of_edge; i++) {
		int from, to, cost;
		std::cin >> from >> to >> cost;
		adj[from].push_back(std::make_pair(cost, to)); // vertext, cost���� ���������
		adj[to].push_back(std::make_pair(cost, from)); // �ϰ����� ���� �̷��� ���°� �� ���� ��
	}

	// ���������� �� �������� �ּҺ�� ����ϱ�
	std::vector<int> distances = dijkstra(start_vertex);
	for (int i = 0; i < distances.size(); i++) {
		std::cout << "���������� " << i << "�������� �Ÿ� : " << distances[i] << '\n';
	}

	// �ִ� ��� ����ϱ�
	std::vector<int> sp;
	int look_for;
	
	std::cout << "ã���� �ϴ� ��� number : ";
	std::cin >> look_for;
	sp = shortestPath(look_for);
	for (int i : sp) {
		std::cout << i << ' ';
	}

	return 0;
}