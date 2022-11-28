#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> arr)
{
	for (int a : arr) {
		std::cout << a << ' ';
	}
	std::cout << '\n';
}

int main()
{
	std::vector<int> array = { 3, 1, 2, 4, 5 };
	print(array);	

	// 오름차순 정렬
	sort(array.begin(), array.end());
	print(array);

	// 내림차순 정렬(reverse iterator 활용)
	sort(array.rbegin(), array.rend());
	print(array);

	// 내림차순 정렬(sort 속성 활용)
	sort(array.begin(), array.end(), std::greater<>());
	print(array);

	return 0;
}