#include <iostream>

// 완벽한 전달을 사용하는 함수.
template<typename F, typename T>
decltype(auto) chronometry(F f, T arg) // int arg = 0
{
	return f(arg);
}


void foo(int* p) {}

int main()
{
	int n = 0;

	int* p1 = 0; // ok
//	int* p2 = n; // error. 핵심. literal 0 만 포인터 초기화에 사용가능하고
			     //             0을 가진 정수형 변수는 포인터 초기화에 사용못함
	foo(0);	// ok
//	foo(n); // error

	chronometry(foo, 0);	// error
							// foo(0) 이 아닌
							// foo(arg) 가 된것.. 
//	chronometry(foo, &n); // 에러는 아니지만,
							// 널포인터(0)을 보내고 싶었는데.
							// 의미 없는 주소를 준것

	chronometry(foo, nullptr); // ok.
}
