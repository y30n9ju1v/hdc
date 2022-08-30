#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 특정 함수의 성능을 측정하는 함수를 생각해 봅시다.
template<typename F, typename T>
void chronometry(F f, T arg)
{
	// 현재 시간 기록
	f(arg);	// 함수 호출
	// 걸린 시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
