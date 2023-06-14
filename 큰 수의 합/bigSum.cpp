#include <string>
#include <algorithm>

void bigSum(std::string& result, std::string num1, std::string num2)
{
	int sum = 0; // ���� �ڸ��� �� + �ø������� �ؼ� 3���� ���� ���� ��
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		} // ��������� sum�� �� ���� ������ ��
		result.push_back((sum % 10 + '0')); // ������� ���� ���� 1�� �ڸ��� �ְ�
		sum /= 10; // �ø����� ���ܵΰ�
	}
	reverse(result.begin(), result.end());
}

/* reverse ���� ����
string = sum + string ó�� ���� �Ǹ� �迭�� ���ʿ� ���� ������ �迭 �� �о���� ��
�ʹ� �ӵ��� ������
�׷��� �׳� ���ʿ� �� �ְ� ���� �Ŀ� �������� �ѹ��� ������ �ִ� ��

�� �ӵ� ������ ���ؼ�!
*/