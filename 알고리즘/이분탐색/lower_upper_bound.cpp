/* lower_bound와 upper_bound

두 함수 또한 이진탐색을 기반으로 하므로 정렬된 배열에서만 사용할 수 있다.
- lower_bound : 찾고자 하는 값 이상이 처음 나타나는 iterator 반환
- upper_bound : 찾고자 하는 값 초과가 처음 나타나는 iterator 반환

즉, { 1, 2, 4, 4, 6, 7 }에서 lower_bound는 4이상이 처음 나타나는 위치인 2를 return
                             upper_bound는 4초과가 처음 나타나는 위치인 4를 return

★ 위의 두 함수를 이용하여 upper - lower을 해주면 해당 배열에 들어있는 4의 갯수를 알 수 있다.
배열 안에서 값 k의 갯수를 구하라고 한다면 count로 for문 돌리면 O(N)이지만
upper_bound결과 - lower_bound결과 하면 O(logN)이 되므로 더 유리하다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> array{ 1, 2, 4, 4, 6, 7 };

	int target = 4;
	int l = lower_bound(array.begin(), array.end(), target) - array.begin();
	int u = upper_bound(array.begin(), array.end(), target) - array.begin();
	std::cout << l << '\n'; // 2
	std::cout << u << '\n'; // 4

	// 중복값을 구하는 문제라면
	std::cout << "target의 갯수는 " << u - l << "개 입니다.\n";

	return 0;
}