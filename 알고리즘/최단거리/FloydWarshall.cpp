/* 최단거리 알고리즘 플로이드 와샬(Floyd_Warshall)

가중치가 각자 다르고 음수가중치가 있을 때, 음의 가중치가 없을때

M:N으로 한번에 모든 정점간의 거리를 계산함
*/

#include <iostream>
#include <vector>

#define INF 99999 // 23line에 distance간의 덧셈이 있어서 2147483647로 쓰면 오버플로우나서 음수가 되서 항상 작아지므로 오류발생함

std::vector<std::vector<int>> distance;

void Floyd_Warshall(int nov)
{
	// 시간복잡도 V^3
	// i, j, k = 1은 정점 1번부터 세는 경우, 0번부터 센다면 0으로
	for (int k = 1; k < nov; k++)  // k 는 거쳐가는 정점
		for (int i = 1; i < nov; i++)  // i 는 행 (출발 정점)
			for (int j = 1; j < nov; j++)  // j 는 열 (도착 정점)
				if (distance[i][k] + distance[k][j] < distance[i][j])  // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
					distance[i][j] = distance[i][k] + distance[k][j];

	// 결과 출력
	for (int i = 1; i < nov; i++) {
		for (int j = 1; j < nov; j++) {
			std::cout << distance[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	int number_of_vertex, number_of_edge; // M:N이므로 시작정점은 필요없음
	std::cin >> number_of_vertex >> number_of_edge;

	// nov+1하는 이유는 보통 정점을 1번부터 세기때문, 만약 0번부터 센다면 그냥 +1 안해도 됨
	distance.resize(number_of_vertex + 1, std::vector<int>(number_of_vertex + 1, INF)); // 전부 INF로 초기화
	for (int i = 0; i < number_of_vertex + 1; i++) {
		distance[i][i] = 0; // 자기자신까지의 거리는 0
	}

	for (int i = 0; i < number_of_edge; i++) {
		int from, to, cost;
		std::cin >> from >> to >> cost;
		distance[from][to] = cost;
	}

	Floyd_Warshall(number_of_vertex + 1);

	return 0;
}