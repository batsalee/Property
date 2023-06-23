/*
idx번째 비트끄기
S &= ~(1 << idx)

idx번째 비트 XOR 연산
S ^= (1 << idx)

최하위 켜져있는 비트 찾기
idx = (S & -S)

크기가 n인 집합의 모든 비트를 켜기
(1 << n) - 1

idx번째 비트를 켜기
S |= (1 << idx)

idx번째 비트가 켜져 있는지 확인하기
if (S & (1 << idx))

*/

// 비트 끄기 예시코드
#include <bits/stdc++.h>

using namespace std;

int main() {
    int S = 18;
    int idx = 1;
    S &= ~(1 << idx);
    cout << S << '\n'; // 16
    return 0;
}