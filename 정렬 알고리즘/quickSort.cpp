/*
Quick Sort(�� ����)

- �ð����⵵ : O(n*logn), ���������� �׷��� ������ ��Ȯ�� �ݹ� ���� �� ���
   			   O(n��), �׷��� ������ ���ϰ� ���Ī������ �򸮴� ���
			   �̰� ���� ���� pivot�� �����ϴ� ���� ������� ����
               ��������� �ſ� ���� �ӵ������� O(n*logn)�� ���� O(n��)�� ���� ������
			   high rist - high return�̶�� �� ���� ����

- ���� : ������ ������ �� �ִ� ������ ���� ���� ����� ��� �߱� ����
         ���� ���� ����̶� ū ������ ���� ������ �ɰ��� �ذ��ϴ� ���
		 �ѹ��� ��� ���ſ� ���� ���ݾ� �������� ���� �� ����
		 ����Ʈ �ȿ��� �� ��Ҹ� �����ϰ� �̰� pivot(�ǹ�)�̶�� �θ�
		 �ǹ��� �������� �ǹ����� ���� ��ҵ��� ���� �ǹ� �������� �̵�, �ǹ����� ũ�� ���� �ǹ� ���������� �̵�
		 �̷��� �Ǹ� �ǹ��� �߰� ��򰡿� ���� �ǰ�
		 �׷� ���� �ǹ� ���ʰ� �����ʿ� ����Ʈ�� ���� ����� �Ǵµ� �ű⼭ �� ���� �ݺ�

- ���� : ����Լ��� ����
		 �˰����� pivot, low, high�� �ְ� pivot�� ���� ��
		 low�� ���ʺ��� ���������� pivot���� ū ���� ã��
		 high�� �����ʺ��� �������� pivot���� �������� ã�� �� ���� ��ȯ
		 �̰� low�� high�� ������������ �ݺ��ϸ�
		 pivot�� ���ʿ� pivot���� ���� ������, pivot�� �����ʿ� pivot���� ū ������ ���̰� ��
		 �� ���� �� ���� �迭, ������ �迭 ���� �Ȱ��� �˰����� �迭�� ���Ұ� 1���϶����� �ݺ�
*/

#include "quickSort.h"

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int arr[], int start, int end) {
	if (start >= end) return;
	int pivot = start; // pivot�� ù������ ����
	int left = start + 1;
	int right = end;

	while (left <= right) {
		while (arr[left] <= arr[pivot]) left++;
		while (arr[right] >= arr[pivot] && right > start) right--;

		if (left > right) swap(&arr[right], &arr[pivot]);
		else swap(&arr[left], &arr[right]);

		quickSort(arr, start, right - 1);
		quickSort(arr, right + 1, end);
	}
}

/* testcase
#include <iostream>
#include "quickSort.h"

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

	quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	std::cout << "���� �� : ";
	print(arr);

	return 0;
}
*/