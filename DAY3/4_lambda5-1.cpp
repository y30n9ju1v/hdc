#include <iostream>

// 핵심 1. 람다표현식을 auto 변수에 담는 것은 global 에서도 가능합니다.
auto add = [](int a, int b) {return a + b; }; 


template<typename T>
void foo(T f)
{
//  decltype(f) f2; // xxx f2;
					// => C++20 부터 가능. C++17 까지는 에러
					// => 람다표현식을 보고 컴파일러가 만드는 클래스는
					//    디폴트 생성자 없음.

	decltype(f) f2(f); // ok.. 복사 생성자는 있습니다.

}

int main()
{
	auto f = [](int a, int b) {return a + b; };
			// class xxx{}; xxx();		
			// => main 함수 안에서 클래스가 생성된것
	foo(f);

}