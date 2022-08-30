#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

// 핵심 : 완벽한 전달을 하려면

// 1. 인자를 받을때 T&& 로 받으세요
// => lvalue, rvalue 를 모두 받을수 있는데.
// => rvalue 를 받을때 lvalue 로 변하게 됩니다.

// 2. 인자를 다른곳에 전달할때 "std::forward<T>(arg)" 로 묶어서 보내세요.

// T&& : 대부분 전달받은 인자를 다른 곳에 보낼때 주로 사용합니다.
//       그래서, "forwarding reference" 라고 합니다.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
//	f(static_cast<T&&>(arg));

	f(std::forward<T>(arg)); // std::forward 가 위 코드와 같은 캐스팅수행
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	
	chronometry(goo, n);	
}
