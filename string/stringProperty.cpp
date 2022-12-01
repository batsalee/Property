#include <iostream>
#include "stringProperty.h"

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
	매개변수로 char을 넣어야 함
	char이 ['0'-'9']면 true고 아니면 false
	int로 넣으면 안됨, '0'+int로 넣는 식이던가 해야할듯한데 그냥 char만 쓴다고 생각하기
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
	*/

	std::string str = "123abc12";
	int num;
	
	if (str != "") {
		num = stoi(str);
	}

	std::cout << num << std::endl;
}