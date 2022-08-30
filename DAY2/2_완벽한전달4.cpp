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
// chronometry(10)==>   int&& arg = 10 ���� �ް�
//						hoo(arg)	=======================> error
//					    ��, �����鼭 value �Ӽ��� ����
//					    hoo(static_cast<int&&>(arg)) ======> ok

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10; ����
	// 1. 10�� rvalue �Դϴ�.
	// 2. arg�� lvalue �Դϴ�.

//	f(arg); // ��, arg �� lvalue �̹Ƿ� �� �ڵ��
			// "hoo(int&)" �� ã�� �˴ϴ�
			// �׷���, hoo(int&&) �̹Ƿ� 
			// "rvalue reference�� lvalue �� ������ ����"�� ����.
	f(static_cast<int&&>(arg)); // ok. 
			// => 10�̶�� rvalue �� �����鼭 lvalue(arg)�� �� ����
			// => �ٽ� rvalue �� �����ؼ� ����
}




int main()
{
	hoo(10); 
	chronometry(hoo, 10);	
}
