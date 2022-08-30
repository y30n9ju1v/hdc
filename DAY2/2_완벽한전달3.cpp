#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {} // <=== �̹� �ҽ��� �ٽ� �Լ�..

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok
	chronometry(hoo, 10);	// hoo(10) �� �ǵ� �ε�..
							// �� �����ϱ�� ??
							// �ذ��� �����ҽ�����.. 
}
