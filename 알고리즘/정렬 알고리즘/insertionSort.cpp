/*
insertion sort(삽입 정렬)

- 시간복잡도 : O(n²), 최악의 상황에선 O(n²)이지만 최선의 상황에선 O(n)이라서 버블이나 선택보다 좋음
   			   이미 거의 정렬이 된 상태에선 효율이 좋지만, 역순에 가까우면 효율이 매우 나쁨
- 개념 : 이미 정렬되어 있는 배열에 새로운 숫자가 들어 갈 때 알맞은 위치를 찾아서 그 자리로 들어간다.
         만약 3번 인덱스라면 0, 1, 2번 인덱스가 이미 정렬되어 있으니 그 중 제 자리 찾아가는 방식
         3번을 2번과 비교, 3번이 더 크다면 그냥 다음 인덱스로, 3번이 더 작다면 3번과 2번 swap
         2번이 된 3번과 1번을 또 비교해서 또 더 작다면 swap, 아니면 다음 인덱스로

- 구현 : 코드상에서는 swap을 줄이기 위해 대입하는 방식으로 구현
         3번 차례라면 temp에 3번을 넣고 시작
         3번과 2번을 비교해서 2번이 더 크다면 3번자리에 2번을 대입함
		 2번이 된 3번과 1번을 비교해서 1번이 더 작다면 2번 자리에 temp 대입
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
	std::cout << "정렬 전 : ";
	print(arr);

	insertionSort(arr, sizeof(arr)/sizeof(arr[0]));
	std::cout << "정렬 후 : ";
	print(arr);

	return 0;
}

*/