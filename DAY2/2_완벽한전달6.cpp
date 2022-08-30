#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

// �ٽ� : �Ϻ��� ������ �Ϸ���

// 1. ���ڸ� ������ T&& �� ��������
// => lvalue, rvalue �� ��� ������ �ִµ�.
// => rvalue �� ������ lvalue �� ���ϰ� �˴ϴ�.

// 2. ���ڸ� �ٸ����� �����Ҷ� "std::forward<T>(arg)" �� ��� ��������.

// T&& : ��κ� ���޹��� ���ڸ� �ٸ� ���� ������ �ַ� ����մϴ�.
//       �׷���, "forwarding reference" ��� �մϴ�.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
//	f(static_cast<T&&>(arg));

	f(std::forward<T>(arg)); // std::forward �� �� �ڵ�� ���� ĳ���ü���
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	
	chronometry(goo, n);	
}
