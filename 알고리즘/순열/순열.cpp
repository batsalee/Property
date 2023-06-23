/*
���� 1) ������������ ���ĵ� �����̳ʷθ� ��� ����
���� 2) default���� ������������ �� ���� �����̴�
���� 3) �ߺ��� ���Ұ� �ִٸ� ��������� �ѹ��� �����
        ������� ������ { 0 0 1 }�̶��
        6���� ������ �ƴ� �ߺ� ���ܵ� {0 0 1}, {0 1 0}, {1 0 0} 3������ �������

bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);
���� ������ �����ϸ� �ش� �����̳ʸ� ���� ������ ����� true�� ����
���� ������ ���ٸ� false�� ����

���� ������ prev_permutation
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