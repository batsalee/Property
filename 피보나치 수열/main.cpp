#include <iostream>
#include <vector>

int fib(int n) // 재귀 방식
{	
	if (n == 1 || n == 2) {
		return 1;
	}
	else return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) // DP 방식
{
	std::vector<int> f(n+1);
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

int main()
{
	int input;
	std::cin >> input;

	fib(input);
	fibonacci(input);

	return 0;
}
