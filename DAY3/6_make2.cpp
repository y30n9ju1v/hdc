#include <iostream>
#include <tuple>
#include <string>
using namespace std::literals;

int main()
{
	std::pair<int, double> p1(3, 3.4);
	std::tuple<int, double, int, double> t1(3, 3.4, 3, 3.4);

	// 위처럼 pair, tuple 을 직접 사용하면 타입을 꼭 전달해야 합니다.
	// make_ 함수 사용하세요
	auto p2 = std::make_pair(3, 3.4);
	auto t2 = std::make_tuple(3, 3.4, 3, 3.4f, "a", "a"s);
									// const char*, std::string

	// 그런데, C++17 부터는 클래스 템플릿도 타입추론 가능합니다.

	std::tuple t3(3, 3.4, 3, 3.4); // ok. C++17 부터.
}