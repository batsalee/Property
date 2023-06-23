/* �̺�Ž��
* 
�������� low(Ȥ�� left), �߰����� mid, ������ high(Ȥ�� right)
�������� ������ �迭�� ó���� ���� ����Ű�� mid�� �迭�� �߾��ε������� ���� Ȯ������ �ε����� �ǹ�
�� ã���� �ϴ� ���� mid�ε����� ���� ���ϸ� �˻� ������ ����

1. �˻� �������� �߰� ��(mid)�� �����ؼ� ã���� �ϴ� ��(target)�� ������ Ȯ��
2. if (mid�� �� == target) ��� mid�� ��ȯ
3. if (mid�� �� < target) ��� �˻� ������ �� ū������ �Űܾ��ϹǷ� low = mid + 1;
4. if (mid�� �� > target) ��� �˻� ������ �� ���������� �Űܾ� �ϹǷ� high = mid - 1;
5. 1 ~ 4�� ������ �ݺ��ϴٰ� mid�� �� == target�̶�� mid�� ��ȯ
6. ���� �迭�� target�� ���ٸ� low > high�� �ǹǷ� if(low > high) return -1;

*/


/* C++ STL ���
index ����� �ȵǰ� ���� ������ true/false�� �˷��ִ� ��
algorithm ��� include
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


/* �ݺ��� ���
*/
#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& arr, int low, int high, int target) {
	while (low <= high) {
		int mid = (low + high) / 2;

		if (target == arr[mid]) return mid; // ���� ã�Ҵٸ� �ش� ���� index ��ȯ
		else if (target < arr[mid]) high = mid - 1; // ã�� ���� �� ������ �˻� ������ ���� ������
		else if (target > arr[mid]) low = mid + 1; // ã�� ���� �� ũ�� �˻� ������ ū ������
	}
	return -1; // ���������� ��ã�´ٸ� -1 ��ȯ
}

int main()
{
	std::vector<int> array{ 1, 3, 5, 7, 9, 11, 13 };

	std::cout << "7�� �ε��� : " << binarySearch(array, 0, array.size() - 1, 7) << '\n';
}


/* ��� ���
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

	std::cout << "7�� �ε��� : " << binarySearch(array, 0, array.size() - 1, 7) << '\n';
}