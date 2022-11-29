#include "selectionSort.h"

void selectionSort(int arr[], size_t size)
{
	for (int i = 0; i < size - 1; i++) {
		
		// 배열 중 최솟값 찾기
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}

		// 최솟값을 앞쪽에 놓기 위해 swap
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}

/*testcase
#include <iostream>
#include "selectionSort.h"

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

	selectionSort(arr, sizeof(arr)/sizeof(arr[0]));
	std::cout << "정렬 후 : ";
	print(arr);

	return 0;
}
*/