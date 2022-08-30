#include <iostream>
#include <type_traits>

// C90. memset, memcpy 에 의존하지 말라!

class Test
{
	int data;
public:
	virtual void foo() {}
};

void init(Test* p)
{
	// C++ 클래스도 "memset" 해도 되지만, 권장하지는 않습니다.
	static_assert(std::is_trivial<Test>::value,
					"error T is not trivial type");

	// is_trivial : 모든 특수함수(생성자, 복사, 소멸자, move등)이 
	//				모두 trivial 한 타입.

	memset(p, 0, sizeof(Test));
}

int main()
{
	Test* p = new Test;

	init(p);
	p->foo();

	delete p;
}