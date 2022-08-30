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
	// T&& �� rvalue reference ��� �����ϸ� �ȵ˴ϴ�.
	//       "forwarding reference" �Դϴ�.
	//       ���ڷ� lvalue �� ���´���, rvalue �� ���´����� ����޶� ���ϴ�.
	f(static_cast<T&&>(arg));
	// => �� ĳ������ "rvalue" ĳ������ �ƴմϴ�

	// "(���ڷ�) rvalue �� (�����ϸ�) rvalue �� ĳ�����ϰ�
	//          lvalue ��          lvalue �� ĳ�����մϴ�.

}

int main()
{
	int n = 0;
	chronometry(foo, 10);	// T=int, T&&=int&&, chronometry( int&&)
							// static_cast<int&&>(arg)

	chronometry(goo, n);	// T=int&, T&&=int& &&, chronometry(int&)
							// static_cast<int&>(arg)
}
