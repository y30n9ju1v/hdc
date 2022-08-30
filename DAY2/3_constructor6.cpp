#include <iostream>

// C50_ Use a factory function if you need ��virtual behavior��
// during initialization

// "�����ڿ� �Ҹ��ڿ����� �����Լ��� ȣ������ ����."
// => �����Լ��� �������� �ʽ��ϴ�.

struct Base
{
	Base() { init(); }  // ������ Base init()
						// ���� �̼��� Derived init()�� ȣ��ȴٸ� ������ �ֽ��ϴ�.
						// => Derived::init �� ����ϴ� "�������Ÿ(x)"��
						//    �ʱ�ȭ ���� ���� ���°� �˴ϴ�.


	void foo() { init(); }; // this->init() �ε�
							// foo �ȿ��� this�� Base* Ÿ���Դϴ�
							// => init �� �����Լ��� �ƴϸ� "Base init"
							// => init �� �����Լ����     "Derived init"
							

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1
};

struct Derived : public Base
{
	int x;
	// ����� �ڵ�			// �����Ϸ��� �����Ѱ�. x�ʱ�ȭ ���� Base()������ ȣ��
	Derived() : x(10) {}	// Derived() : Base(), x(10) {}

	virtual void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
};


int main()
{
	Derived d;
//	d.foo();   // ��� ������ ������
}

