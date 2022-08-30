#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {} // <=== 이번 소스의 핵심 함수..

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok
	chronometry(hoo, 10);	// hoo(10) 의 의도 인데..
							// 왜 에러일까요 ??
							// 해결은 다음소스에서.. 
}
