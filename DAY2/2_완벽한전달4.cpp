#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main						chronometry						hoo(int&&)
// hoo(10)=================================================> ok
// chronometry(10)==>   int&& arg = 10 으로 받고
//						hoo(arg)	=======================> error
//					    즉, 받으면서 value 속성이 변경
//					    hoo(static_cast<int&&>(arg)) ======> ok

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10; 에서
	// 1. 10은 rvalue 입니다.
	// 2. arg는 lvalue 입니다.

//	f(arg); // 즉, arg 는 lvalue 이므로 이 코드는
			// "hoo(int&)" 를 찾게 됩니다
			// 그런데, hoo(int&&) 이므로 
			// "rvalue reference에 lvalue 를 보낼수 없다"는 에러.
	f(static_cast<int&&>(arg)); // ok. 
			// => 10이라는 rvalue 를 받으면서 lvalue(arg)로 된 것을
			// => 다시 rvalue 로 변경해서 전달
}




int main()
{
	hoo(10); 
	chronometry(hoo, 10);	
}
