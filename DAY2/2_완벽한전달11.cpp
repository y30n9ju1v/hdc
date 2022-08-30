#include <iostream>

void f0()      { printf("f0\n"); }
void f1(int a) { printf("f1 : %d\n", a); }
void f3(int a, double d, int& r) { r = 200; }

// �Ϻ��� ������
// 1. ���� ���� ���ø����� �ϴ� ��찡 �����ϴ�.

template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)
{
	f( std::forward<T>(arg)... );
}

int main()
{
	int n = 0;
	chronometry(f1);
	chronometry(f2, 10);
	chronometry(f3, 10, 3.4, n);

	std::cout << n << std::endl;
}
