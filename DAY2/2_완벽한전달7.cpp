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
//	X obj = arg;	// arg 는 무조건 lvalue 입니다. 
					// => 이 코드는 항상 복사 생성자 호출

//	X obj = std::move(arg); // std::move 의 목표는 move 생성자를 호출하기 위한것
							// => std::move 는 무조건 rvalue 로 캐스팅합니다.
	
	X obj = std::forward<T>(arg);	// 인자를 보낼때 lvalue, rvalue 여부에 따라
									// 달라집니다.
							// => lvalue 를 보냈으면 lvalue 캐스팅(COPY)
							// => rvalue ""        rvalue      (MOVE 호출)		
}

int main()
{
	X x;
	fn(x);   // lvalue 전달
	fn(X()); // rvalue 전달
}