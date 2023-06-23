/* lower_bound�� upper_bound

�� �Լ� ���� ����Ž���� ������� �ϹǷ� ���ĵ� �迭������ ����� �� �ִ�.
- lower_bound : ã���� �ϴ� �� �̻��� ó�� ��Ÿ���� iterator ��ȯ
- upper_bound : ã���� �ϴ� �� �ʰ��� ó�� ��Ÿ���� iterator ��ȯ

��, { 1, 2, 4, 4, 6, 7 }���� lower_bound�� 4�̻��� ó�� ��Ÿ���� ��ġ�� 2�� return
                             upper_bound�� 4�ʰ��� ó�� ��Ÿ���� ��ġ�� 4�� return

�� ���� �� �Լ��� �̿��Ͽ� upper - lower�� ���ָ� �ش� �迭�� ����ִ� 4�� ������ �� �� �ִ�.
�迭 �ȿ��� �� k�� ������ ���϶�� �Ѵٸ� count�� for�� ������ O(N)������
upper_bound��� - lower_bound��� �ϸ� O(logN)�� �ǹǷ� �� �����ϴ�.
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

	// �ߺ����� ���ϴ� �������
	std::cout << "target�� ������ " << u - l << "�� �Դϴ�.\n";

	return 0;
}