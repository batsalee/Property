/* ����Ʈ��(FenwickTree)

�ڼ��� ���� ������ https://smallpants.tistory.com/124

*/

#include <iostream>
#include <vector>

// 0���ε����� ������� �ʱ����� 0 �Ѱ� �ٿ���
// ������ �迭�� 1���� 16
std::vector<int> arr{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
std::vector<int> Fenwick_Tree(17, 0);
int N = 16;

void Update(int Idx, int diff)
{
    while (Idx < Fenwick_Tree.size()) {
        Fenwick_Tree[Idx] = Fenwick_Tree[Idx] + diff;
        Idx = Idx + (Idx & -Idx);
    }
}

void Make_FenwickTree()
{
    for (int i = 1; i <= N; i++) {
        Update(i, arr[i]);
    }
}

int Sum(int Idx)
{
    int Result = 0;
    while (Idx > 0) {
        Result = Result + Fenwick_Tree[Idx];
        Idx = Idx - (Idx & -Idx);
    }
    return Result;
}

int main()
{
    Make_FenwickTree();
    std::cout << Sum(3) << '\n'; // 6���

    int Index = 1;
    int Value = 5;
    int Diff = Value - arr[Index];
    Update(Index, Diff);
    std::cout << Sum(3) << '\n'; // 10���

    return 0;
}