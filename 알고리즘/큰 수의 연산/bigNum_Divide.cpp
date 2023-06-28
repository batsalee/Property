#include <string>

// a를 b로 나눈 몫 구하기 (제수는 long long 범위 이내)
std::string bigNum_Divide(std::string& a, long long b) {
    long long temp = 0;
    std::string result;
    for (long long i = 0; i < a.length(); i++) {
        temp = (temp * 10) + (a[i] - '0');
        result += (temp / b) + '0';
        temp %= b;
    }

    int zero_count = 0;
    for (char c : result) {
        if (c == '0') zero_count++;
        else break;
    }
    if (result != "0") result = result.substr(zero_count);

    return result;
}