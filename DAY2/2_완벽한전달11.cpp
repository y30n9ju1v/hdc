#include <iostream>

void f0()      { printf("f0\n"); }
void f1(int a) { printf("f1 : %d\n", a); }
void f3(int a, double d, int& r) { r = 200; }

// 완벽한 전달은
// 1. 가변 인자 템플릿으로 하는 경우가 많습니다.

template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)
{
	f( std::forward<T>(arg)... );
}

int main()
{
	int n = 0;
	chronometry(f1);
	chronometry(f2, 10);
	chronometry(f3, 10, 3.4, n);

	std::cout << n << std::endl;
}
