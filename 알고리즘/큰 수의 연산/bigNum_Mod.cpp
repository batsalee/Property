#include <string>

// a를 b로 나눈 나머지 구하기 (제수는 long long 범위 이내)
long long bigNum_Mod(std::string& a, long long b) {
    long long result = 0;

    for (long long i = 0; i < a.length(); i++) {
        result = (result * 10) + (a[i] - '0');
        result %= b;
    }

    return result;
}