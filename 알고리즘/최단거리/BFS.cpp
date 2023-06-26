/* �ִܰŸ� �˰��� BFS

����ġ�� ���ų� ��� ���� ��
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> adj; // �׷����� ���� ����Ʈ ǥ��
std::vector<int> distance; // �� ������ �ִܰŸ�
std::vector<int> parent; // �ִܰ�θ� ����ϱ� ����

void bfs(int start)
{
	distance[start] = 0; // �������� �ڱ� �ڽ��̴� �Ÿ��� 0
	std::queue<int> q;
	q.push(start);

	while (q.size()) {
		int here = q.front();
		q.pop();
		for (int there : adj[here]) {
			if (distance[there] == -1) {
				q.push(there);
				distance[there] = distance[here] + 1; // ����ġ ������ 1��� ����ġ
				parent[there] = here; // �θ� ���� ������ �߰�
			}
		}
	}
}

std::vector<int> shortestPath(int v) // v������ �ִ� ��� func
{
	std::vector<int> path;
	path.push_back(v); // �ڱ��ڽ� �ְ� ����

	while (parent[v] != -1) {
		v = parent[v];
		path.push_back(v);
	}
	reverse(path.begin(), path.end()); // �ڽĳ����� �θ�������� �ö����� �������� ����
	return path;
}

int main()
{
	int number_of_vertex, number_of_edge, start_vertex;
	std::cin >> number_of_vertex >> number_of_edge >> start_vertex;

	// �� ���ٿ��� nov+1�ϴ� ������ ���� ������ 1������ ���⶧��
	// ���� 0������ ���ٸ� �׳� +1 ���ص� ��
	distance.resize(number_of_vertex + 1, -1);	// ���� -1�� �ʱ�ȭ
	adj.resize(number_of_vertex + 1);
	parent.resize(number_of_vertex + 1, -1);

	int u, v;
	for (int i = 0; i < number_of_edge; i++) {
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(start_vertex);

	// �ִ� ��� ����ϱ�
	std::vector<int> sp;
	std::cout << "ã���� �ϴ� ��� number : ";

	int look_for;
	std::cin >> look_for;
	sp = shortestPath(look_for);
	for (int i : sp) {
		std::cout << i << ' ';
	}

	return 0;
}