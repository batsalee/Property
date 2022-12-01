#include <iostream>
#include <algorithm>

void compare()
{
	/*
	min, max 함수
	두 값 중 더 작은수, 큰수를 return함
	
	만약 비교해야 할 값이 2개보다 많을 경우 중첩으로 사용 가능
	*/
	int a = 1, b = 2;
	std::cout << "더 큰 수는 : " << std::max(a, b) << std::endl;
	std::cout << "더 작은 수는 : " << std::min(a, b) << std::endl;

	// 비교해야 할 값이 많을 경우 중첩으로 사용
	int c = 3, d = 4;
	std::cout << "가장 큰 수는 : " << std::max( std::max(a, b), std::max(c, d) ) << std::endl;
}