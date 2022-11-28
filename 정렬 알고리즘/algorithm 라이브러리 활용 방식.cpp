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

	// �������� ����
	sort(array.begin(), array.end());
	print(array);

	// �������� ����(reverse iterator Ȱ��)
	sort(array.rbegin(), array.rend());
	print(array);

	// �������� ����(sort �Ӽ� Ȱ��)
	sort(array.begin(), array.end(), std::greater<>());
	print(array);

	return 0;
}