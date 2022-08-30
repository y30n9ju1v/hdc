#include <iostream>
#include <type_traits>

// C90. memset, memcpy �� �������� ����!

class Test
{
	int data;
public:
	virtual void foo() {}
};

void init(Test* p)
{
	// C++ Ŭ������ "memset" �ص� ������, ���������� �ʽ��ϴ�.
	static_assert(std::is_trivial<Test>::value,
					"error T is not trivial type");

	// is_trivial : ��� Ư���Լ�(������, ����, �Ҹ���, move��)�� 
	//				��� trivial �� Ÿ��.

	memset(p, 0, sizeof(Test));
}

int main()
{
	Test* p = new Test;

	init(p);
	p->foo();

	delete p;
}