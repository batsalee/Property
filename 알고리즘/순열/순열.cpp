/*
조건 1) 오름차순으로 정렬된 컨테이너로만 사용 가능
조건 2) default값이 오름차순으로 된 순열 생성이다
조건 3) 중복된 원소가 있다면 결과에서는 한번만 출력함
        예를들어 수열이 { 0 0 1 }이라면
        6가지 순열이 아닌 중복 제외된 {0 0 1}, {0 1 0}, {1 0 0} 3가지만 만들어줌

bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);
다음 순열이 존재하면 해당 컨테이너를 다음 순열로 만들고 true를 리턴
다음 순열이 없다면 false를 리턴

이전 순열은 prev_permutation
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{ 1, 2, 3 };

    sort(v.begin(), v.end());

    do {
        for (int _v : v) {
            cout << _v << ' ';
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}