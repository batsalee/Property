/* 최단거리 알고리즘 다익스트라(dijkstra)

가중치가 각자 다르고 모두 양수일 때
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
	// (현위치까지의 distance, 현위치) 형태로 저장

	distance[start] = 0;				// 시작지점의 거리는 0
	pq.push(std::make_pair(0, start));	// (현위치까지의 distance, 현위치)

	while (!pq.empty()) {
		int cost = pq.top().first;		// 방문한 정점의 dist 값 
		int here = pq.top().second;		// 현재 방문한 정점 
		pq.pop();
		if (distance[here] < cost) continue; // 지금 꺼낸 정점이 무시해야하는 정보인지 확인

		for (int i = 0; i < adj[here].size(); i++) {    // 현재 방문한 정점의 주변 정점 모두 조사 
			int there = adj[here][i].second;			// 조사할 다음 정점 
			int thereCost = cost + adj[here][i].first;	// 현재 방문한 정점을 거쳐서 다음 정점을 갈때의 비용 
			if (thereCost < distance[there]) {			// 기존 비용보다 현재 방문한 정점을 거친 비용이 더 싸다면 
				distance[there] = thereCost;			// 갱신 
				pq.push(std::make_pair(thereCost, there));	// pq에 저장 
				parent[there] = here;
			}
		}
	}

	return distance;
}

std::vector<int> shortestPath(int v)
{
	std::vector<int> path;
	path.push_back(v); // 자기자신 넣고 시작

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

	// 이 세줄에서 nov+1하는 이유는 보통 정점을 1번부터 세기때문
	// 만약 0번부터 센다면 그냥 +1 안해도 됨
	distance.resize(number_of_vertex, INF); // 전부 INF로 초기화
	adj.resize(number_of_vertex + 1);
	parent.resize(number_of_vertex, -1);

	for (int i = 0; i < number_of_edge; i++) {
		int from, to, cost;
		std::cin >> from >> to >> cost;
		adj[from].push_back(std::make_pair(cost, to)); // vertext, cost여도 상관없지만
		adj[to].push_back(std::make_pair(cost, from)); // 일관성을 위해 이렇게 쓰는게 더 편한 듯
	}

	// 시작점부터 각 점까지의 최소비용 출력하기
	std::vector<int> distances = dijkstra(start_vertex);
	for (int i = 0; i < distances.size(); i++) {
		std::cout << "시작점부터 " << i << "노드까지의 거리 : " << distances[i] << '\n';
	}

	// 최단 경로 출력하기
	std::vector<int> sp;
	int look_for;
	
	std::cout << "찾고자 하는 노드 number : ";
	std::cin >> look_for;
	sp = shortestPath(look_for);
	for (int i : sp) {
		std::cout << i << ' ';
	}

	return 0;
}