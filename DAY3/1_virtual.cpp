#include <iostream>

// C.140: Do not provide different default arguments 
//        for a virtual function and an overrider

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};

class Derived : public Base
{
public:
	// �ٽ� : �Լ� ������ ����Ʈ ���� �����߽��ϴ�. 
	// => ���� �̷��� �ϸ� �ȵ˴ϴ�.
	// => ������ �ƴ�����.. 
	virtual void foo(int a = 20) { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;
	p->foo(); // Derived : 10
				// 1. �����Ϸ��� p �� Base* ��� �����մϴ�.
				// 2. Base Ŭ�������� foo �Լ��� ������ �����մϴ�.
				// 3. foo �� ���ڰ� �����Ƿ� �����Ϸ��� ������ �ð��� ����Ʈ��
				//    ���� ���ڸ� ä�� �ݴϴ�.
				// "p->foo(10)" �� �ڵ�� ������ �ð��� ����
		
				// 4. �׷���, foo �� �����Լ� �̹Ƿ� ���� ��� �Լ��� ȣ��������
				//	  ����ð��� p�� ����Ű�� ���� �����ؼ� ����
				//    => Derived �� ����Ű�Ƿ� Derived::foo(10)�� ���·� ȣ��
	Derived d;
	d.foo(); // Derived : 20



	// ����Ʈ ���� : ������ �ð��� �����Ϸ��� �߰� �ϴ� ����
	// ���� �Լ�   : ����ð��� �Լ� ȣ���� �����ϴ� ����

	// ������ �ð� ������ ����ð� ������ ȥ���ؼ� ������� ������
}
