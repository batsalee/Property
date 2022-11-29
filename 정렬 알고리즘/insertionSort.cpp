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
	std::cout << "정렬 전 : ";
	print(arr);

	insertionSort(arr, sizeof(arr)/sizeof(arr[0]));
	std::cout << "정렬 후 : ";
	print(arr);

	return 0;
}

*/