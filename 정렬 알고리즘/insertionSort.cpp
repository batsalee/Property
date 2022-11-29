/*
insertion sort(���� ����)

- �ð����⵵ : O(n��), �־��� ��Ȳ���� O(n��)������ �ּ��� ��Ȳ���� O(n)�̶� �����̳� ���ú��� ����
   			   �̹� ���� ������ �� ���¿��� ȿ���� ������, ������ ������ ȿ���� �ſ� ����
- ���� : �̹� ���ĵǾ� �ִ� �迭�� ���ο� ���ڰ� ��� �� �� �˸��� ��ġ�� ã�Ƽ� �� �ڸ��� ����.
         ���� 3�� �ε������ 0, 1, 2�� �ε����� �̹� ���ĵǾ� ������ �� �� �� �ڸ� ã�ư��� ���
         3���� 2���� ��, 3���� �� ũ�ٸ� �׳� ���� �ε�����, 3���� �� �۴ٸ� 3���� 2�� swap
         2���� �� 3���� 1���� �� ���ؼ� �� �� �۴ٸ� swap, �ƴϸ� ���� �ε�����

- ���� : �ڵ�󿡼��� swap�� ���̱� ���� �����ϴ� ������� ����
         3�� ���ʶ�� temp�� 3���� �ְ� ����
         3���� 2���� ���ؼ� 2���� �� ũ�ٸ� 3���ڸ��� 2���� ������
		 2���� �� 3���� 1���� ���ؼ� 1���� �� �۴ٸ� 2�� �ڸ��� temp ����
*/

#include "insertionSort.h"

void insertionSort(int arr[], size_t size)
{
	for (int i = 1; i < size; i++) {
		int temp = arr[i];

		int j = i;
		while(j > 0 && arr[j-1] > temp) {
			arr[j] = arr[j-1];
			j--;
		}

		arr[j] = temp;
	}
}

/* testcase
#include <iostream>
#include "insertionSort.h"

void print(int a[])
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	int arr[5] = {3, 4, 1, 2, 5};
	std::cout << "���� �� : ";
	print(arr);

	insertionSort(arr, sizeof(arr)/sizeof(arr[0]));
	std::cout << "���� �� : ";
	print(arr);

	return 0;
}

*/