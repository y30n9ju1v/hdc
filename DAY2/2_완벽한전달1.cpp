#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding : 전달 받은 인자를 다른 함수에 다시 전달하는 것.
// 
// perfect forwarding(완벽한 전달)
// => 전달 받은 인자에 어떠한 변화도 없이 그대로 전달하는 것.

// 특정 함수의 성능을 측정하는 함수를 생각해 봅시다.
template<typename F, typename T>
void chronometry(F f, const T& arg)
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
