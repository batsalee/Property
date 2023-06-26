/* �ִܰŸ� �˰��� �÷��̵� �ͼ�(Floyd_Warshall)

����ġ�� ���� �ٸ��� ��������ġ�� ���� ��, ���� ����ġ�� ������

M:N���� �ѹ��� ��� �������� �Ÿ��� �����
*/

#include <iostream>
#include <vector>

#define INF 99999 // 23line�� distance���� ������ �־ 2147483647�� ���� �����÷ο쳪�� ������ �Ǽ� �׻� �۾����Ƿ� �����߻���

std::vector<std::vector<int>> distance;

void Floyd_Warshall(int nov)
{
	// �ð����⵵ V^3
	// i, j, k = 1�� ���� 1������ ���� ���, 0������ ���ٸ� 0����
	for (int k = 1; k < nov; k++)  // k �� ���İ��� ����
		for (int i = 1; i < nov; i++)  // i �� �� (��� ����)
			for (int j = 1; j < nov; j++)  // j �� �� (���� ����)
				if (distance[i][k] + distance[k][j] < distance[i][j])  // ��ȭ�� distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
					distance[i][j] = distance[i][k] + distance[k][j];

	// ��� ���
	for (int i = 1; i < nov; i++) {
		for (int j = 1; j < nov; j++) {
			std::cout << distance[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	int number_of_vertex, number_of_edge; // M:N�̹Ƿ� ���������� �ʿ����
	std::cin >> number_of_vertex >> number_of_edge;

	// nov+1�ϴ� ������ ���� ������ 1������ ���⶧��, ���� 0������ ���ٸ� �׳� +1 ���ص� ��
	distance.resize(number_of_vertex + 1, std::vector<int>(number_of_vertex + 1, INF)); // ���� INF�� �ʱ�ȭ
	for (int i = 0; i < number_of_vertex + 1; i++) {
		distance[i][i] = 0; // �ڱ��ڽű����� �Ÿ��� 0
	}

	for (int i = 0; i < number_of_edge; i++) {
		int from, to, cost;
		std::cin >> from >> to >> cost;
		distance[from][to] = cost;
	}

	Floyd_Warshall(number_of_vertex + 1);

	return 0;
}