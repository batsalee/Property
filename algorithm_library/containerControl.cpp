#include <algorithm>
#include <iostream>
#include <vector>

int containerControl()
{
	std::vector<int> array = { 1, 2, 3, 4, 5 };
	for (int i : array) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	/*
	뒤집기
	컨테이너 뿐 아니라 string객체도 잘 뒤집어짐
	reverse(str.begin(), str.end());
	*/
	std::reverse(array.begin(), array.end());
	for (int i : array) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	/*
	회전시키기
	rotate(시작반복자, 첫위치로 올 반복자, 종료반복자)
	begin()+1 즉 두번째 자리가 첫위치로 간다는건 왼쪽으로 한칸씩 이동한다는 뜻이므로
	*/
	// 한칸씩 왼쪽 이동
	std::rotate(array.begin(), array.begin() + 1, array.end()); 
	// 한칸씩 오른쪽 이동
	std::rotate(array.begin(), array.end() - 1, array.end()); 

	return 0;
}