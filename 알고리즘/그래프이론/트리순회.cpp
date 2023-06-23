#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1004];
int visited[1004];

void postOrder(int here) { // ������ȸ
	if (visited[here] == 0) {
		if (adj[here].size() == 1)postOrder(adj[here][0]);
		if (adj[here].size() == 2) {
			postOrder(adj[here][0]);
			postOrder(adj[here][1]);
		}
		visited[here] = 1;
		cout << here << ' ';
	}
}

void preOrder(int here) { // ������ȸ
	if (visited[here] == 0) {
		visited[here] = 1;
		cout << here << ' ';
		if (adj[here].size() == 1)preOrder(adj[here][0]);
		if (adj[here].size() == 2) {
			preOrder(adj[here][0]);
			preOrder(adj[here][1]);
		}
	}
}

void inOrder(int here) { // ������ȸ
	if (visited[here] == 0) {
		if (adj[here].size() == 1) {
			inOrder(adj[here][0]);
			visited[here] = 1;
			cout << here << ' ';
		}
		else if (adj[here].size() == 2) {
			inOrder(adj[here][0]);

			visited[here] = 1;
			cout << here << ' ';

			inOrder(adj[here][1]);
		}
		else {
			visited[here] = 1;
			cout << here << ' ';
		}
	}

}

int main() {
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	int root = 1;

	cout << "\n Ʈ����ȸ : postOrder \n";
	postOrder(root); memset(visited, 0, sizeof(visited));

	cout << "\n Ʈ����ȸ : preOrder \n";
	preOrder(root); memset(visited, 0, sizeof(visited));

	cout << "\n Ʈ����ȸ : inOrder \n";
	inOrder(root);

	return 0;
}