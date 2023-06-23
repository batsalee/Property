/* 이분탐색
* 
시작점은 low(혹은 left), 중간점은 mid, 끝점은 high(혹은 right)
시작점과 끝점은 배열의 처음과 끝을 가리키며 mid는 배열의 중앙인덱스이자 실제 확인중인 인덱스를 의미
즉 찾고자 하는 값과 mid인덱스의 값을 비교하며 검사 범위를 변경

1. 검사 범위에서 중간 값(mid)를 선택해서 찾고자 하는 값(target)과 같은지 확인
2. if (mid의 값 == target) 라면 mid를 반환
3. if (mid의 값 < target) 라면 검사 범위를 더 큰쪽으로 옮겨야하므로 low = mid + 1;
4. if (mid의 값 > target) 라면 검사 범위를 더 작은쪽으로 옮겨야 하므로 high = mid - 1;
5. 1 ~ 4의 과정을 반복하다가 mid의 값 == target이라면 mid를 반환
6. 만약 배열에 target이 없다면 low > high가 되므로 if(low > high) return -1;

*/


/* C++ STL 방식
index 출력은 안되고 존재 유무만 true/false로 알려주는 듯
algorithm 헤더 include
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> array{ 1, 3, 5, 7, 9, 11, 13 };

	bool isFound = binary_search(array.begin(), array.end(), 7);
	std::cout << std::boolalpha << isFound << '\n';

	return 0;
}


/* 반복문 방식
*/
#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& arr, int low, int high, int target) {
	while (low <= high) {
		int mid = (low + high) / 2;

		if (target == arr[mid]) return mid; // 값을 찾았다면 해당 값의 index 반환
		else if (target < arr[mid]) high = mid - 1; // 찾는 값이 더 작으면 검사 범위를 작은 쪽으로
		else if (target > arr[mid]) low = mid + 1; // 찾는 값이 더 크면 검사 범위를 큰 쪽으로
	}
	return -1; // 마지막까지 못찾는다면 -1 반환
}

int main()
{
	std::vector<int> array{ 1, 3, 5, 7, 9, 11, 13 };

	std::cout << "7의 인덱스 : " << binarySearch(array, 0, array.size() - 1, 7) << '\n';
}


/* 재귀 방식
*/
#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& arr, int low, int high, int target) {
	if (low > high) return -1;

	int mid = (low + high) / 2;

	if (target == arr[mid]) return mid;
	else if (target > arr[mid]) return binarySearch(arr, mid + 1, high, target);
	else if (target < arr[mid]) return binarySearch(arr, low, mid - 1, target);
}

int main()
{
	std::vector<int> array{ 1, 3, 5, 7, 9, 11, 13 };

	std::cout << "7의 인덱스 : " << binarySearch(array, 0, array.size() - 1, 7) << '\n';
}