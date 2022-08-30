#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	// 생성된 함수의 이름을 출력해 보면 됩니다.
//	std::cout << __func__ << std::endl; // C++표준. 함수 이름만 출력

	std::cout << __FUNCSIG__ << std::endl; // 인자를 포함한 함수이름
										// 단, C++표준이 아님. vc만가능

//	std::cout << __PRETTY_FUNCTION__ << std::endl; // g++전용
											// vc 안됨.
}

int main()
{
	int n = 10;

	foo(n);  //	T=int&    T&&=int& &&		foo(int&)
	foo(10); // T=int	  T&&=int&&         foo(int&&)
}




