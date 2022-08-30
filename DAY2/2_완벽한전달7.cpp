#include <iostream>

class X
{
public:
	X() = default; // 디폴트 생성자 요청

	X(const X&)     { std::cout << "COPY 생성자" << std::endl; }
	X(X&&) noexcept { std::cout << "MOVE 생성자" << std::endl; }
};
// 핵심 1. T& 와 T&& 의 차이점을 이해 하세요
// T&  : 임의 타입의 lvalue 만 전달 받겠다는 의도
// T&& : 임의 타입의 lvalue, rvalue 를 모두 전달 받겠다는 의도

// 핵심 2. std::move() 와 std::forward() 의 차이점을 완벽히 이해 하세요

template<typename T> void fn(T&& arg)
{
	T obj = arg;
}
int main()
{
	X x;
	fn(x);   // lvalue 전달
	fn(X()); // rvalue 전달
}