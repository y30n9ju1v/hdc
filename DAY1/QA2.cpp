// QA2
#include <iostream>

void fn(int& n)  { std::cout << "int&" << std::endl; }   // 1
void fn(int&& n) { std::cout << "int&&" << std::endl; }  // 2
	// => fn(int&&) : rvalue 를 받겠다는 것입니다.
	//				  rvalue reference 타입을 받는 것이 아닙니다.
int main()
{
	int n = 0;
	fn(n);	// n 은 이름이 있습니다. lvalue 입니다.		- 1번호출
	fn(3);  // 3 은 이름이 없고 값만 있습니다. rvalue	- 2번호출
			// rvalue 이므로 "3 = 10" 은 안됩니다.

	int&& r = 3;

	fn(r); // 1번호출

	//		타입			value속성
	// 3	int			rvalue
	// n	int			lvalue
	// r    int&&		lvalue

	fn(static_cast<int&&>(r)); // 2번 호출
				// r의 타입이 int&& 인데, 같은 타입 캐스팅 아닌가요 ?
				// => 이 코드는 "타입 캐스팅" 이 아닙니다.
				// => lvalue 를 rvalue 로 변경하는 "value 캐스팅" 입니다.
}