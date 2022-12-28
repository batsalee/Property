/*
getline 함수 사용법은 2가지가 있음
1) 배열을 이용하는 경우
2) string 객체를 이용하는 경우

배열을 이용하는 경우는 
#include <iostream> 헤더를 포함해주고
std::cin.getline(char* s, streamstring n, char delim); 의 함수원형으로 사용
- s : 문자열을 저장할 변수
- n : 저장할 문자의 개수
그리고 문자열의 마지막에 null을 추가로 저장

string 객체를 이용하는 경우
#include <iostream>과 #include <string> 헤더를 포함해주고
std::getline(istream& is, string& str, char delim); 의 함수 원형으로 사용
- is : 파일 입력 또는 표준 입력
- str : 문자열을 저장할 string 변수
- delim : 하나의 문자를 지정해서 해당 문자까지 저장할 수 있음, 생략 가능
*/

#include <iostream>
#include <string>

int main() {
	
	std::string input;
	std::getline(std::cin, input);

	return 0;
}