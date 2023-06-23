/* LIS

���� ���� �κ� ����(LIS, Longest Increasing Subsequence)

���Ұ� N���� �迭���� �Ϻ� ���Ҹ� ��󳻼� ���� �κ� ���� ��, 
�� ���Ұ� ���� ���Һ��� ũ�鼭 �κм����� ���̰� �ִ��� ������ ���� ���� �κм����̶�� ��

arr[] = { 6, 2, 5, 1, 7, 4, 8, 3 };�̶�� LIS�� { 2, 5, 7, 8 } �� �Ǵ� ��
{2, 5}�� {2, 7}�̳� {1, 7}�� �����ϴ� �κм����� �������� �� �� ���� ����� { 2, 5, 7, 8 }�̹Ƿ�

DP���, ���׸�ƮƮ�� Ȱ����, �̺�Ž����� 3������ �ִµ� �̺�Ž������� ���� �����Ƿ� �ַ� ����ҵ�

*/

/*
* 
������

�̺�Ž�� lower_bound�� ���

1) ���͸� ������ �� -INF(���� �� ���� ���� ���� ��)�� ����
2) ������ �������� ������ �� �� ���ҿ� ���� ������ ���Ҹ� ���ؼ�
   ������ ���Ұ� �� ũ�� push_back�ϰ� LIS++
   ������ ���Ұ� �� ������ lower_bound�� �̿��ؼ� ������ �ڸ��� ã�Ƽ� �� �ڸ��� ���� �ش� ������ ���ҷ� ��ü

�ڼ��� �����ϰ� ������ https://smallpants.tistory.com/126

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

    std::cout << "lis ���� : " << length_of_lis; // 6 ���

    return 0;
}