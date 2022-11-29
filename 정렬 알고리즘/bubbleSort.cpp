/* 
bubble sort(버블 정렬)

- 시간 복잡도 : O(n²), 가장 쉽지만, 시간 복잡도가 높아 비효율적

- 개념 : 인접한 두 값을 비교해서 순서대로 되어있지 않으면 교환
		 더 큰값을 뒤로 보내면서 뽀글뽀글 올라가는 모양새

- 구현 : 0번원소와 1번원소를 비교하고 0번이 더 크다면 교환, 1번과 2번을 비교 후 1번이 더 크다면 교환
		 반복하면 가장 큰 수가 가장 마지막 인덱스로 가게 됨
		 그럼 이제 마지막 인덱스 제외하고 다시 반복
*/

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