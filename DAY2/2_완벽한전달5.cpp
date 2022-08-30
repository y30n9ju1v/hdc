#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

// 핵심 : 완벽한 전달을 하려면
// 1. int&, int&& 버전을 따로 만들고
// 2. int&& 버전에서는 인자를 forwarding 할때, rvalue로 캐스팅후 전달
/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg));	// 필요없는 캐스팅이고,
								// 컴파일시에 결국 제거 됩니다.
								// 하지만 있어도 됩니다.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/
// forwarding reference(T&&) 를 사용하면 위 2개를 자동생성할수 있습니다.
// => 그런데, 템플릿을 사용하려면 2개 함수의 구현이 같아야 합니다.
template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	// T=?, T&&, chronometry( ? )
							// static_cast<?>(arg)

	chronometry(goo, n);	// T=?, T&&, chronometry( ? )
							// static_cast<?>(arg)
}
