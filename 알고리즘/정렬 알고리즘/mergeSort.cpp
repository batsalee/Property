/*
Merge Sort(병합 정렬)(=합병 정렬)

- 시간복잡도 : O(nlogn), 퀵 정렬과 다르게 최악의 경우에도 O(nlogn)을 보장
   			   퀵정렬의 시간복잡도가 늘어나는 이유는 비대칭으로 분할 될 수 있기 때문인데
			   병합정렬은 무조건 1개 단위로 분할되니 O(nlogn) 보장
			   하지만 메모리를 더 많이 사용하고 그 과정에서 "평균적으로" 퀵정렬보다 느린 성능

- 개념 : 병합정렬인 이유가 이름 뜻대로 병합할때 정렬이 되기 때문
         먼저 배열을 절반씩 나눔
		 나눠진 배열을 또 각각 절반씩 나눔
		 이렇게 되서 1개씩 나눠지면 다시 합치기 시작함
		 이때 합칠때 두개를 비교해서 정렬해서 합침
		 또 합칠때 비교해서 정렬하고 합침
		 반복하면 다 합쳐질때 정렬 끝

- 구현 : 값 비교를 편하게 하기 위해 배열 복사 후 사용
		 1개씩 모두 분리 한 후 비교하면서 복사된 배열에 채워넣음
		 마무리로 남은쪽의 값들을 전부 채워 넣음
*/

#include "mergeSort.h"

int result[5];

void mergeSort(int arr[], int start, int end)
{
	partition(arr, start, end);
}

// 분할
void partition(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		partition(arr, left, mid);
		partition(arr, mid + 1, right);
		merge(arr, left, right);
	}
}

// 병합
void merge(int arr[], int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			result[k++] = arr[i++];
		else
			result[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) result[k++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = result[i];
}

/* test case
#include <iostream>
#include "mergeSort.h"

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

	mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	std::cout << "정렬 후 : ";
	print(arr);

	return 0;
}
*/