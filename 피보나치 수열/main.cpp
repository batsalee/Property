#include <iostream>
#include <vector>

int fib(int n) // Àç±Í¹æ½Ä
{	
	if (n == 1 || n == 2) {
		return 1;
	}
	else return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) // µ¿Àû°èÈ¹¹ý
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