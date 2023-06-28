#include <string>
#include <algorithm>

std::string bigNum_Add(std::string num1, std::string num2)
{
	std::string result = "";
	int temp = 0; // 현재 자릿수 둘 + 올림수까지 해서 3개의 합이 들어가는 곳
	while (!num1.empty() || !num2.empty() || temp) {
		if (!num1.empty()) {
			temp += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			temp += num2.back() - '0';
			num2.pop_back();
		} // 여기까지가 temp에 각 수를 더해준 것
		result.push_back((temp % 10 + '0')); // 결과에는 계산된 합의 1의 자릿수 넣고
		temp /= 10; // 올림수는 남겨두고
	}
	reverse(result.begin(), result.end());

	return result;
}

/* reverse 쓰는 이유
string = temp + string 처럼 쓰게 되면 배열의 앞쪽에 값을 넣으니 배열 다 밀어줘야 함
너무 속도가 느려짐
그래서 그냥 뒷쪽에 다 넣게 만든 후에 마지막에 한번에 뒤집어 주는 것

즉 속도 개선을 위해서!
*/