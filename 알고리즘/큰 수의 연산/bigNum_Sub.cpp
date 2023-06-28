#include <string>
#include <algorithm>

std::string bigNum_Sub(std::string& num1, std::string& num2) {

    // a�� �� ū�� b�� �� ū�� Ȯ��
    // b�� �� ũ�ٸ� a,b �����ϰ� ������� - ���̱�
    bool is_bigger_num2;
    if (num1.length() > num2.length()) {
        is_bigger_num2 = false;
    }
    else if (num1.length() < num2.length()) {
        swap(num1, num2);
        is_bigger_num2 = true;
    }
    else {
        for (int i = 0; i < num1.length(); i++) {
            if (num1[i] > num2[i])
                is_bigger_num2 = false;
            else if (num1[i] < num2[i]) {
                swap(num1, num2);
                is_bigger_num2 = true;
            }
        }
    }

    bool CR = false;
    int temp = 0;
    std::string result;
    while (!num1.empty() || !num2.empty() || temp) {
        if (!num1.empty()) {
            temp += num1.back() - '0';
            num1.pop_back();
            if (CR) { temp--; CR = false; }
        }
        if (!num2.empty()) {
            temp -= num2.back() - '0';
            num2.pop_back();
        }
        if (temp < 0) { // �� ���� ������ �� ����, ĳ�� üũ
            temp = 10 - abs(temp);
            CR = true;
        }
        result.push_back((temp + '0')); // ������� ���� ���� 1�� �ڸ��� �ְ�
        temp = 0;
    }

    // �տ� ���� 0 ����
    int zero_count = 0;
    for (auto itr = result.rbegin(); *itr == '0'; itr++) {
        zero_count++;
    }
    if (result != "0") result = result.substr(0, result.length() - zero_count);

    if (is_bigger_num2) result += '-';     // check()���� swap�� ��� ����    
    reverse(result.begin(), result.end());

    return result;
}