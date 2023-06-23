#include <iostream>
#include <sstream>

void stringStream()
{
    /*
    stringstream

    #include <sstream>

    문자열에 여러가지 자료형이 한번에 들어올때 파싱해서 자르기 위해 사용
    예를들어 "날짜 일정" 이런식으로 들어오면
    날짜는 int로 자르고, 일정은 string으로 자르고

    stringstream은 공백과 '\n'을 제외하고 정보를 빼냄
    stream.str(string s)는 현재 stream의 값을 문자열 str로 바꿈

    stream >> 연산자로 한개씩 다음 값을 넣어줄 수 있음
    */

    std::string info = "뱃살 생일 1105";
    std::stringstream stream;
    stream.str(info);

    std::string part;
    while (stream >> part)
        std::cout << part << std::endl;
}
