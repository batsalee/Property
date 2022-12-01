#include <iostream>

void main()
{
    /*
    pair template Class
    두개의 연관된 데이터를 다룰때 편리하게 사용 가능

    #include <utility>가 필요하지만
    #include <algorithm>이나
    #include <vector>에 이미 utility 헤더가 포함되어있음
    그러니 algorithm이나 vector를 포함한다면 utility는 안해도 된다

    template <class T1, class T2> struct pair;
    T1은 first로 접근, T2는 second로 접근

    사용법
    pair<type1, type2> p로 pair클래스의 p 객체를 생성
    p.first는 p의 첫번째 인자
    p.second는 p의 두번째 인자
    make_pair(값1, 값2)는 값1, 값2를 한 쌍으로 하는 pair를 리턴해줌

    pair객체간의 비교시 first로 먼저 비교하고 같으면 second로 비교한다
    */

    std::pair<int, int> ip;
    ip.first = 1;
    ip.first = 2; // 이런식으로 대입도 가능

    std::cout << "ip.first : " << ip.first << ", ip.second : " << ip.second << std::endl;

    std::pair<int, double> idp(1, 2.5); // 이런식으로초기화도 가능
    std::cout << "idp.first : " << idp.first << ", idp.second : " << idp.second << std::endl;

    std::pair<std::string, int> sip;
    sip = std::make_pair("스트링", 10); // make_pair를 사용해 대입도 가능
    std::cout << "sip.first : " << sip.first << ", sip.second : " << sip.second << std::endl;
}
