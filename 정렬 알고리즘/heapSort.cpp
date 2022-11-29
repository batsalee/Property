/*
Heap Sort(힙 정렬)

- 시간복잡도 : O(nlogn), 시간복잡도가 좋은 편이며 메모리 사용이 필요없다는 점에서 병합 정렬의 단점이 보완 됨
  			   힙 정렬이 가장 유용한 경우는 전체 자료를 정렬하는게 아니라 가장 큰(작은) 값 몇개만 필요할 때

- 개념 : 먼저 힙(heap)에 대해 알아야 함
  1) heap의 개념
    힙이란 완전이진트리 형태로 만들어진 자료구조이며, 무언가를 차곡차곡 쌓아올린 더미라는 뜻
	일반적으로 힙이라고 하면 최대 힙을 의미함
	최대 힙(max heap) : 완전이진트리이면서 (부모노드>자식노드)
	최소 힙(min heap) : 완전이진트리이면서 (부모노드<자식노드)

  2) 힙의 장점 : 최댓값 혹은 최솟값을 빠르게 찾아내기에 유리한 자료구조

  3) 힙을 만드는 법
	값 삽입 -> 힙 구조로 변경 -> 값 삽입 -> 힙 구조로 변경 -> ... 반복
	4 1 5 2 3 순의 배열이 있다면 먼저 4가 부모노드 자리에 들어가고,
	그 후 1이 자식노드 자리에 들어감, 이 떄 자식노드가 부모노드보다 크지 않은지 확인하고
	크지 않으면 다음 인덱스로 넘어가고, 더 크다면 부모노드와 swap 해줌, 이걸 반복
	자식노드간의 크기는 비교하지 않음

  4) heap 정렬의 개념
	오름차순 정렬을 위해서는 최대힙을 구성, 내림차순 정렬을 위해서는 최소힙을 구성
	힙 자료구조를 이용해 완전이진트리를 만들면 최대값, 혹은 최대값을 구할 수 있음
	그 최대값, 혹은 최소값을 제외하고 나머지를 또 정리해서 다음 최대값, 최소값을 구하는 것

- 구현
  정렬할 요소들로 완전이진트리형태를 만듬
  만약 오름차순 정렬이라면 최대힙으로 구성해서 가장 위 노드에 최대값이 올라감
  그럼 이 최대값을 가장 마지막 node의 값과 swap해줌
  그 다음 힙 구조 정리를 0~N-1 까지만 해주면 가장 큰 값은 가장 마지막 자리에서 움직이지 않게 됨
  힙 구조 정리가 되면 또 마지막-1번째 node와 swap해주고 0~N-2까지만 정리 반복
*/

#include "heapSort.h"

void swap(int* val1, int* val2) {
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

void heapify(int arr[], int len, int parent) {
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < len && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < len && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != parent) {

        swap(&arr[parent], &arr[largest]);

        heapify(arr, len, largest);
    }
}

void heapSort(int arr[], int len) {

    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(arr, len, i);
    }

    for (int i = len - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


/* test case
#include <iostream>
#include "heapSort.h"

void print(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    int arr[5] = { 3, 4, 1, 2, 5 };

    std::cout << "정렬 전 : ";
    print(arr);

    heapSort(arr, sizeof(arr) / sizeof(arr[0]));

    std::cout << "정렬 후 : ";
    print(arr);

    return 0;
}
*/