#include <iostream>

struct Base
{
	int value = 10; 
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl; // 20

	// 기반 클래스 멤버에 접근하려면, 기반 클래스 타입으로 캐스팅하면 됩니다.
	// => 아래 2줄의 차이점을 생각해 보세요.
	std::cout << static_cast<Base>(d).value << std::endl;  // 10
	std::cout << static_cast<Base&>(d).value << std::endl; // 10

//	static_cast<Base>(d).value = 30; // error
									 // temporary 는 왼쪽에 올수없다.
	static_cast<Base&>(d).value = 30; // ok
}
// temporary 는
// 1. 개발자가 의도적으로 만들기도 합니다
// => 함수 인자로 객체 전달.  foo(Point(1,2))

// 2. 개발자가 만든 다양한 코드에서 자동 생성되기도 합니다
// => 함수가 객체를 "값 타입"으로 반환 할때
// => 객체를 "값 타입"으로 캐스팅 할때

// 언제, 임시객체가 생성되는지 정확히 알고 있어야 합니다.






