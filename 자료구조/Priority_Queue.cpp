/* �켱���� ť(Priority Queue)

Queue�� �� �����̸� �׳� ���Լ����� ������ �ƴ϶� ������ �켱������ ���� ������ ���ĵǾ� �ִ� Queue

�Ϲ����� Queue��� ���� ���� ���� �տ�, �� ���߿� ���� ���� �ڿ� ������� ������
Priority Queue�� ���� ���� ������ �켱������� Queue�� ���ĵǰ�, pop�� ���ĵ� Queue�� �տ��� �̷����

Heap���� �����Ǿ� �����Ƿ� Push �� ���ĵǴ� ������ O(logN)���� �̷����

push(value) : value�� ť�� �߰��Ѵ�.
pop() : top�� ���Ҹ� �����Ѵ�.
top() : top�� ���Ҹ� ��ȯ�Ѵ�.���Ŵ� ���� ����
empty() : ��������� return true, �ƴϸ� return false
size() : �켱���� ť�� ���Ե� ������ �� return

*/

#include <iostream>
#include <queue> // priority_queue ����� ���� �ʿ�

int main()
{
	/* default priority_queue

	priority_queue<�ڷ���> ������;
	ex) priority_queue<int> pq;

	push�� ������ ������������ ����
	���������� �ƴ϶� ���������� default�ΰ��� �����ؾ� ��
	*/
	std::priority_queue<int> pq1;
	pq1.push(2);
	pq1.push(1);
	pq1.push(4);
	pq1.push(3);
	for (int i = 0; i < 4; i++) {
		std::cout << pq1.top() << ' ';
		pq1.pop();
	} // 4 3 2 1 ���

	std::cout << '\n';

	/* ������ priority_queue

	priority_queue<�ڷ���, Container, ���Լ�> ������;
	ex) priority_queue<int, vector<int>, cmp> pq;

	�⺻�� ���������̹Ƿ� sort�� �ݴ�� cmp�ڸ��� greater<>�� ������ ���������� ��
	*/
	std::priority_queue<int, std::vector<int>, std::greater<>> pq2;
	pq2.push(2);
	pq2.push(1);
	pq2.push(4);
	pq2.push(3);
	for (int i = 0; i < 4; i++) {
		std::cout << pq2.top() << ' ';
		pq2.pop();
	} // 1 2 3 4 ���

	std::cout << '\n';

	/* ���� ���� ���� ���ϱ�

	���� �Լ��� template ���̶� �׷��� ������ ���°� ����
	�׷��Ƿ� cmp�� ���� ����ٸ�
	*/
	struct cmp {
		bool operator()(int n1, int n2) {
			if (abs(n1) > abs(n2)) return true;
			else if (abs(n1) == abs(n2)) {
				if (n1 > n2) return true;
				else return false;
			}
			else return false;
		}
	};

	std::priority_queue<int, std::vector<int>, cmp> pq3;
	pq3.push(2);
	pq3.push(-2);
	pq3.push(-4);
	pq3.push(6);
	for (int i = 0; i < 4; i++) {
		std::cout << pq3.top() << ' ';
		pq3.pop();
	}

	return 0;
}