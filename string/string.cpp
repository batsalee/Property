#include <iostream>

void checkCharacter()
{
	/*
	isupper(c) : 대문자라면 true
	islower(c) : 소문자라면 true
	*/
	char lower = 'a';
	if (isupper(lower)) std::cout << lower << "는 대문자입니다" << std::endl;
	else if (islower(lower)) std::cout << lower << "는 소문자입니다" << std::endl;

	/*
	isdigit 주의점
	매개변수로 char을 넣어야 함, string이나 int는 안됨
	char이 ['0'-'9']면 true고 아니면 false

	string객체로 isdigit 사용법
	if(isdigit(*part.c_str()))
	c_str()을 하면 string to char*가 되고, c_str의 결과물은 char가 아니라 char*이므로
	char포인터의 값을 빼오기 위해 *part.c_str()로 사용해 줌
	*/
	char c = '2';
	if (isdigit(c)) std::cout << c << "는 숫자입니다" << std::endl;

	/*
	isspace : 공백이면 true
	isalpha : 알파벳이면 true
	*/
	char space = ' ';
	if (isspace(space)) std::cout << space << "는 공백입니다" << std::endl;

	char alpha = 'p';
	if (isalpha(alpha)) std::cout << alpha << "는 알파벳입니다" << std::endl;
}

void changeCharacter()
{
	/*
	toupper(c) : 대문자로 변경
	tolowwer(c) : 소문자로 변경
	*/
	char alpha = 'a';
	std::cout << alpha << "는 소문자입니다." << std::endl;

	alpha = toupper(alpha);
	std::cout << alpha << "는 대문자입니다." << std::endl;

	alpha = tolower(alpha);
	std::cout << alpha << "는 소문자입니다." << std::endl;
}

#include <string>

void changeString()
{
	/*
	stoi 등등 주의점
	1) #include <string>
	2) char가 아닌 string을 매개변수로 넣어야 함
	3) string i = "123";을 stoi(i)하면 int형의 123으로 잘 되지만
	   string i = "123abc45";를 stoi(i)하면 문자 앞까지만 변환되서 123으로 변환됨
	4) 변환 후 넣어줄 변수가 long long이면 stoi를 쓰면 안되고 stoll을 써야함
	5) stoi(buffer);를 했을때 buffer가 비어있으면 core dump가 뜨니까 먼저 확인하고 써주기
	   if(buffer != "") stoi(buffer); 처럼

	stoi : string to int
	stof : string to float
	stol : string to long
	stod : string to double
	stoul : string to unsigned int
	stoll : string to long long
	stoull : string to unsigned long long
	stold : string to long double

	atoi처럼 a시리즈는 char*를 사용할 때, stoi처럼 s시리즈는 string을 사용할 때
	*/

	std::string str = "123abc12";
	int num;

	if (str != "") {
		num = stoi(str);
	}

	std::cout << num << std::endl;
}

void stringFind()
{
	/*
	보이어-무어 알고리즘을 쓰면
	문자열에서 그냥 find를 쓰는것보다 훠얼씬 빠르다고 함

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

int main() {
	std::string s =
	"I believe I can fly I believe I can fly I believe I can fly (woo)";

	std::string needle = "believe";

	auto it =
		std::search(s.begin(), s.end(),
				std::boyer_moore_searcher(needle.begin(), needle.end()));

	if (it != s.end()) {
		std::cout << needle << " found at " << std::distance(s.begin(), it)
			  << std::endl;
	} else {
		std::cout << needle << " not found " << std::endl;
	}
}

	*/

	/*
	문자나 문자열 모두 찾을 수 있음
	*/
	string str = "012abc!@#";
	int index = str.find("abc");
	if (index != string::npos) std::cout << "찾는 문자열이 존재합니다." << std::endl;
}

void stringErase()
{
	// 문자열에서 맨 앞의 연속된 0을 지우고 싶다면
	s.remove_prefix(std::min(s.find_first_not_of("0"), s.size()));
	// 맨 뒤의 연속된 0을 지우고 싶다면
	s.remove_suffix(std::min(s.size() - s.find_last_not_of("0") - 1, s.size()));


	// vec내의 3을 모두 지우고 싶다면
	vec.erase(remove(vec.begin(), vec.end(), 3), vec.end());
}