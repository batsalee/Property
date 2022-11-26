#include <iostream>
#include <vector>
#include <cmath>

/*
�Ϲ������δ� �Ҽ� �Ǻ��Ҷ� 2~sqrt(n)���� �ϸ� ��
���� n ���� Ȯ���� �ʿ� ����
������ ���� �Ǻ��ؾ� �� ���� ���ٸ� �����佺�׳׽��� ü �˰��� ���

bool is_primenumber(int n)
{
	if (n < 2) return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
*/

/*
�Ǻ��ؾ� �� ���� �ʹ� ���Ƽ� �ð��� �����ɸ��ٸ�
�Ʒ��� �����佺�׳׽��� ü �˰����� ����ϴ°� �ӵ��鿡�� �ξ� ������

�ٵ� �ڵ带 ������ �޸𸮸� ����ؼ� �ӵ��� ��� �� ������
��Ȳ �� ���鼭 ���� ���� �� �ϴ�.

���� std::endl�� flush������ �ӵ� ������ ���� �� ������
�ӵ��� ���� ���� ����� ��ŭ \n ����ϱ�
*/
void is_primenumber(int min, int max)
{
    std::vector<bool> arr(max + 1, true);
	arr[0] = false;
	arr[1] = false;

	for (int i = 2; i <= sqrt(max); i++) {
		if (arr[i])
		{
			for (int j = 2 * i; j <= max; j += i) {
				arr[j] = false;
			}
		}
    }

    for (int i = min; i <= max; i++) {
        if (arr[i]) std::cout << i << '\n';
    }
}

int main()
{
	int num1, num2;
	std::cin >> num1 >> num2;
	
	is_primenumber(num1, num2);
	
	return 0;
}