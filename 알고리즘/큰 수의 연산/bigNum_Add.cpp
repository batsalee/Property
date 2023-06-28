#include <string>
#include <algorithm>

std::string bigNum_Add(std::string num1, std::string num2)
{
	std::string result = "";
	int temp = 0; // ���� �ڸ��� �� + �ø������� �ؼ� 3���� ���� ���� ��
	while (!num1.empty() || !num2.empty() || temp) {
		if (!num1.empty()) {
			temp += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			temp += num2.back() - '0';
			num2.pop_back();
		} // ��������� temp�� �� ���� ������ ��
		result.push_back((temp % 10 + '0')); // ������� ���� ���� 1�� �ڸ��� �ְ�
		temp /= 10; // �ø����� ���ܵΰ�
	}
	reverse(result.begin(), result.end());

	return result;
}

/* reverse ���� ����
string = temp + string ó�� ���� �Ǹ� �迭�� ���ʿ� ���� ������ �迭 �� �о���� ��
�ʹ� �ӵ��� ������
�׷��� �׳� ���ʿ� �� �ְ� ���� �Ŀ� �������� �ѹ��� ������ �ִ� ��

�� �ӵ� ������ ���ؼ�!
*/