#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{
	auto f = [](int a, int b) { return a + b; };
			 // class xxx{ operator(); }; xxx();

//	auto&       f1 = [](int a, int b) { return a + b; }; // error
//	const auto& f2 = [](int a, int b) { return a + b; }; // ok

	// 핵심 1. 람다표현식의 최종 결과는 "임시객체(rvalue)" 입니다.
	
	// 핵심 2. 모든 람다 표현식은 다른 타입 입니다.

	auto f1 = [](int a, int b) { return a + b; };
				// class xxxx{}; xxxx();

	auto f2 = [](int a, int b) { return a + b; };
				// class yyyy{}; yyyy();

	// f1, f2는 같은 타입일까요 ?? 다른 타입 일까요 ?
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
}