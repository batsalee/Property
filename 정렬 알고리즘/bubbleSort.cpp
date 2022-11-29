#include "bubbleSort.h"

void bubbleSort(int arr[], size_t size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 1; j < size - i; j++) {
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

/* test case
#include <iostream>
#include "bubbleSort.h"

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
	std::cout << "정렬 전 : ";
	print(arr);

	bubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
	std::cout << "정렬 후 : ";
	print(arr);

	return 0;
}
*/