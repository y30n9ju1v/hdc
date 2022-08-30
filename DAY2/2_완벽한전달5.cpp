#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

// �ٽ� : �Ϻ��� ������ �Ϸ���
// 1. int&, int&& ������ ���� �����
// 2. int&& ���������� ���ڸ� forwarding �Ҷ�, rvalue�� ĳ������ ����
/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg));	// �ʿ���� ĳ�����̰�,
								// �����Ͻÿ� �ᱹ ���� �˴ϴ�.
								// ������ �־ �˴ϴ�.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/
// forwarding reference(T&&) �� ����ϸ� �� 2���� �ڵ������Ҽ� �ֽ��ϴ�.
// => �׷���, ���ø��� ����Ϸ��� 2�� �Լ��� ������ ���ƾ� �մϴ�.
template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	// T=?, T&&, chronometry( ? )
							// static_cast<?>(arg)

	chronometry(goo, n);	// T=?, T&&, chronometry( ? )
							// static_cast<?>(arg)
}
