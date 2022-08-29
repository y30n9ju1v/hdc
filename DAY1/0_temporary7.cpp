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

	// ��� Ŭ���� ����� �����Ϸ���, ��� Ŭ���� Ÿ������ ĳ�����ϸ� �˴ϴ�.
	// => �Ʒ� 2���� �������� ������ ������.
	std::cout << static_cast<Base>(d).value << std::endl;  // 10
	std::cout << static_cast<Base&>(d).value << std::endl; // 10

//	static_cast<Base>(d).value = 30; // error
									 // temporary �� ���ʿ� �ü�����.
	static_cast<Base&>(d).value = 30; // ok
}
// temporary ��
// 1. �����ڰ� �ǵ������� ����⵵ �մϴ�
// => �Լ� ���ڷ� ��ü ����.  foo(Point(1,2))

// 2. �����ڰ� ���� �پ��� �ڵ忡�� �ڵ� �����Ǳ⵵ �մϴ�
// => �Լ��� ��ü�� "�� Ÿ��"���� ��ȯ �Ҷ�
// => ��ü�� "�� Ÿ��"���� ĳ���� �Ҷ�

// ����, �ӽð�ü�� �����Ǵ��� ��Ȯ�� �˰� �־�� �մϴ�.






