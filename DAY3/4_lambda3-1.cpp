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
	

}