/* 우선순위 큐(Priority Queue)

Queue의 한 종류이며 그냥 선입선출의 개념이 아니라 지정된 우선순위에 따라 값들이 정렬되어 있는 Queue

일반적인 Queue라면 먼저 넣은 값이 앞에, 더 나중에 넣은 값이 뒤에 순서대로 들어가지만
Priority Queue는 값이 들어가면 지정된 우선순위대로 Queue가 정렬되고, pop은 정렬된 Queue의 앞에서 이루어짐

Heap으로 구현되어 있으므로 Push 후 정렬되는 과정은 O(logN)으로 이루어짐

push(value) : value를 큐에 추가한다.
pop() : top의 원소를 제거한다.
top() : top의 원소를 반환한다.제거는 하지 않음
empty() : 비어있으면 return true, 아니면 return false
size() : 우선순위 큐에 포함된 원소의 수 return

*/

#include <iostream>
#include <queue> // priority_queue 사용을 위해 필요

int main()
{
	/* default priority_queue

	priority_queue<자료형> 변수명;
	ex) priority_queue<int> pq;

	push된 값들을 내림차순으로 정렬
	오름차순이 아니라 내림차순이 default인것을 주의해야 함
	*/
	std::priority_queue<int> pq1;
	pq1.push(2);
	pq1.push(1);
	pq1.push(4);
	pq1.push(3);
	for (int i = 0; i < 4; i++) {
		std::cout << pq1.top() << ' ';
		pq1.pop();
	} // 4 3 2 1 출력

	std::cout << '\n';

	/* 조건형 priority_queue

	priority_queue<자료형, Container, 비교함수> 변수명;
	ex) priority_queue<int, vector<int>, cmp> pq;

	기본이 내림차순이므로 sort와 반대로 cmp자리에 greater<>를 넣으면 오름차순이 됨
	*/
	std::priority_queue<int, std::vector<int>, std::greater<>> pq2;
	pq2.push(2);
	pq2.push(1);
	pq2.push(4);
	pq2.push(3);
	for (int i = 0; i < 4; i++) {
		std::cout << pq2.top() << ' ';
		pq2.pop();
	} // 1 2 3 4 출력

	std::cout << '\n';

	/* 정렬 조건 직접 정하기

	람다 함수가 template 안이라서 그런지 오류가 나는거 같음
	그러므로 cmp를 따로 만든다면
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