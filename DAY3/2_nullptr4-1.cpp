// 2_nullptr4-1 - 2번 복사
#include <iostream>

struct mynullptr_t
{
	template<typename T> operator T* () { return 0; }
};
mynullptr_t mynullptr;
//================================================

template<typename F, typename T>
decltype(auto) chronometry(F f, T arg) 
{
	return f(arg);
}

void foo(int* p) {}

int main()
{
	// 아래 2줄의 경우에 T가 추론되는 것을 생각하세요
	chronometry(foo, 0);			// int arg = 0 으로 추론되는데
									// foo(arg) 는 에러!

	chronometry(foo, mynullptr);	// mynullptr_t arg = mynullptr; 으로 추론
									// foo(arg) 인데, arg 는 mynullptr_t 타입
							// mynullptr_t 타입은 모든 포인터로 암시적 형변환가능
}
// nullptr 의 역사
// 1. boost 라이브러리에서 위처럼 만들어서 사용했습니다.
// 2. C++11 을 만들면서는 nullptr 은  "키워드"가 되었지만, 원리는 위와 동일합니다.