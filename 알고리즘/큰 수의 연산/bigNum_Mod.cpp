#include <string>

// a�� b�� ���� ������ ���ϱ� (������ long long ���� �̳�)
long long bigNum_Mod(std::string& a, long long b) {
    long long result = 0;

    for (long long i = 0; i < a.length(); i++) {
        result = (result * 10) + (a[i] - '0');
        result %= b;
    }

    return result;
}