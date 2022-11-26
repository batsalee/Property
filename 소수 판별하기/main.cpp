#include <iostream>
#include <vector>
#include <cmath>

/*
일반적으로는 소수 판별할때 2~sqrt(n)까지 하면 됨
굳이 n 까지 확인할 필요 없다
하지만 정말 판별해야 할 수가 많다면 에라토스테네스의 체 알고리즘 사용

bool is_primenumber(int n)
{
	if (n < 2) return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
*/

/*
판별해야 할 수가 너무 많아서 시간이 오래걸린다면
아래의 에라토스테네스의 체 알고리즘을 사용하는게 속도면에서 훨씬 빠르다

근데 코드를 봐서는 메모리를 희생해서 속도를 얻는 것 같으니
상황 봐 가면서 쓰면 좋을 듯 하다.

또한 std::endl는 flush때문에 속도 느리게 만들 수 있으니
속도를 위해 쓰는 방식인 만큼 \n 사용하기
*/
void is_primenumber(int min, int max)
{
    std::vector<bool> arr(max + 1, true);
	arr[0] = false;
	arr[1] = false;

	for (int i = 2; i <= sqrt(max); i++) {
		if (arr[i])
		{
			for (int j = 2 * i; j <= max; j += i) {
				arr[j] = false;
			}
		}
    }

    for (int i = min; i <= max; i++) {
        if (arr[i]) std::cout << i << '\n';
    }
}

int main()
{
	int num1, num2;
	std::cin >> num1 >> num2;
	
	is_primenumber(num1, num2);
	
	return 0;
}