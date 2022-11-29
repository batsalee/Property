/* 
selection sort(선택 정렬)

- 시간복잡도 : O(n²), 버블정렬보다는 빠르지만 여전히 느린 정렬, 버블정렬에 비해 swap 횟수가 적어서 덜 비효율적임

- 개념 : 배열에서 가장 작은수를 탐색해서 선택하고 그 값이 들어갈 자리에 넣어줌

- 구현 : 배열에서 가장 작은 값을 찾음, 그다음 인덱스0번과 교환
         그다음 인덱스1~max중에 가장 작은수를 선택함, 그다음 인덱스 1과 교환
         그다음 인덱스2~max중에 가장 작은수를 선택함, 그 다음 인덱스2와 교환.... 반복
*/

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