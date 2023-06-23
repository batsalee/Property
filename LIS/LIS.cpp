/* LIS

최장 증가 부분 수열(LIS, Longest Increasing Subsequence)

원소가 N개인 배열에서 일부 원소를 골라내서 만든 부분 수열 중, 
각 원소가 이전 원소보다 크면서 부분수열의 길이가 최대인 수열을 최장 증가 부분수열이라고 함

arr[] = { 6, 2, 5, 1, 7, 4, 8, 3 };이라면 LIS는 { 2, 5, 7, 8 } 이 되는 것
{2, 5}나 {2, 7}이나 {1, 7}등 증가하는 부분수열은 많겠지만 그 중 가장 긴것이 { 2, 5, 7, 8 }이므로

DP방식, 세그먼트트리 활용방식, 이분탐색방식 3가지가 있는데 이분탐색방식이 쉽고 빠르므로 주로 사용할듯

*/

/*
* 
진행방법

이분탐색 lower_bound를 사용

1) 벡터를 생성한 뒤 -INF(나올 수 없는 가장 작은 값)을 삽입
2) 수열을 볼때마다 벡터의 맨 뒤 원소와 현재 수열의 원소를 비교해서
   수열의 원소가 더 크면 push_back하고 LIS++
   수열의 원소가 더 작으면 lower_bound를 이용해서 최적의 자리를 찾아서 그 자리의 값을 해당 수열의 원소로 교체

자세히 이해하고 싶으면 https://smallpants.tistory.com/126

*/

#include <iostream>
#include <vector>

#define INF 2147483647

int main()
{
    int arr[9] = { 10, 20, 40, 25, 20, 50, 30, 70, 85 };
    std::vector<int> vec;
    vec.push_back(-INF);

    int length_of_lis = 0;
    for (int i = 0; i < 9; i++) {
        if (vec.back() < arr[i]) {
            vec.push_back(arr[i]);
            length_of_lis++;
        }
        else {
            auto it = lower_bound(vec.begin(), vec.end(), arr[i]);
            *it = arr[i];
        }
    }

    std::cout << "lis 길이 : " << length_of_lis; // 6 출력

    return 0;
}