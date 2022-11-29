/*
Quick Sort(퀵 정렬)

- 시간복잡도 : O(n*logn), 분할했을때 그룹의 개수가 정확히 반반 나눠 질 경우
   			   O(n²), 그룹의 개수가 심하게 비대칭적으로 쏠리는 경우
			   이걸 막기 위해 pivot을 설정하는 여러 방법들이 있음
               평균적으로 매우 빠른 속도이지만 O(n*logn)일 수도 O(n²)일 수도 있으니
			   high rist - high return이라고 볼 수도 있음

- 개념 : 빠르게 정렬할 수 있는 이유는 분할 정복 방법을 사용 했기 때문
         분할 정복 방법이란 큰 문제를 작은 문제로 쪼개어 해결하는 방식
		 한번에 들기 무거운 짐은 조금씩 여러번에 나눠 들 듯이
		 리스트 안에서 한 요소를 선택하고 이걸 pivot(피벗)이라고 부름
		 피벗을 기준으로 피벗보다 작은 요소들은 전부 피벗 왼쪽으로 이동, 피벗보다 크면 전부 피벗 오른쪽으로 이동
		 이렇게 되면 피벗이 중간 어딘가에 들어가게 되고
		 그럼 이제 피벗 왼쪽과 오른쪽에 리스트가 각각 생기게 되는데 거기서 또 각각 반복

- 구현 : 재귀함수로 구현
		 알고리즘은 pivot, low, high가 있고 pivot을 정한 후
		 low는 왼쪽부터 오른쪽으로 pivot보다 큰 수를 찾고
		 high는 오른쪽부터 왼쪽으로 pivot보다 작은수를 찾은 후 서로 교환
		 이걸 low와 high가 엇갈릴때까지 반복하면
		 pivot의 왼쪽엔 pivot보다 작은 수들이, pivot의 오른쪽엔 pivot보다 큰 수들이 모이게 됨
		 그 다음 또 왼쪽 배열, 오른쪽 배열 각각 똑같은 알고리즘을 배열의 원소가 1개일때까지 반복
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
	int pivot = start; // pivot은 첫값으로 설정
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
	std::cout << "정렬 전 : ";
	print(arr);

	quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	std::cout << "정렬 후 : ";
	print(arr);

	return 0;
}
*/