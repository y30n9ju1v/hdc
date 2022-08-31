// 2_nullptr4-1 - 2번 복사
#include <iostream>

struct mynullptr_t
{
	template<typename T> operator T* () { return 0; }
};
mynullptr_t mynullptr;

template<typename F, typename T>
decltype(auto) chronometry(F f, T arg) 
{
	return f(arg);
}

void foo(int* p) {}

int main()
{
	// 아래 2줄의 경우에 T가 추론되는 것을 생각하세요
	chronometry(foo, 0);
	chronometry(foo, mynullptr);
}
