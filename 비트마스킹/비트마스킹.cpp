/*
idx��° ��Ʈ����
S &= ~(1 << idx)

idx��° ��Ʈ XOR ����
S ^= (1 << idx)

������ �����ִ� ��Ʈ ã��
idx = (S & -S)

ũ�Ⱑ n�� ������ ��� ��Ʈ�� �ѱ�
(1 << n) - 1

idx��° ��Ʈ�� �ѱ�
S |= (1 << idx)

idx��° ��Ʈ�� ���� �ִ��� Ȯ���ϱ�
if (S & (1 << idx))

*/

// ��Ʈ ���� �����ڵ�
#include <bits/stdc++.h>

using namespace std;

int main() {
    int S = 18;
    int idx = 1;
    S &= ~(1 << idx);
    cout << S << '\n'; // 16
    return 0;
}