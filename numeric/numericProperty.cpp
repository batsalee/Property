#include <iostream>
#include <numeric>
#include "numericProperty.h"

void numericProperty()
{
	/*
	gcd, lcm 사용시 주의사항
	c++ 17버전에 numeric헤더에 추가된 개념이므로 프로젝트 속성 -> 언어 -> 언어버전 17이상해줘야함

	GCD : 최대공약수
	LCM : 최소공배수
	최소공배수 = a * b / 최대공약수;
	lcm(a, b) = a * b / gcd(a, b);
	*/
	int num1 = 35, num2 = 56;
	std::cout << "num1과 num2의 최대공약수 : " << std::gcd(num1, num2) << std::endl;
	std::cout << "num1과 num2의 최소공배수 : " << std::lcm(num1, num2) << std::endl;

	/*
	유클리드 호제법
	int gcd(int a, int b)
	{
		int c;
		while(b != 0) {
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}

	int lcm(int a, int b)
	{
		return a * b / gcd(a, b);
	}
	*/
}