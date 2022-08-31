#include <iostream>

// �Ϻ��� ������ ����ϴ� �Լ�.
template<typename F, typename T>
decltype(auto) chronometry(F f, T arg) // int arg = 0
{
	return f(arg);
}


void foo(int* p) {}

int main()
{
	int n = 0;

	int* p1 = 0; // ok
//	int* p2 = n; // error. �ٽ�. literal 0 �� ������ �ʱ�ȭ�� ��밡���ϰ�
			     //             0�� ���� ������ ������ ������ �ʱ�ȭ�� ������
	foo(0);	// ok
//	foo(n); // error

	chronometry(foo, 0);	// error
							// foo(0) �� �ƴ�
							// foo(arg) �� �Ȱ�.. 
//	chronometry(foo, &n); // ������ �ƴ�����,
							// ��������(0)�� ������ �;��µ�.
							// �ǹ� ���� �ּҸ� �ذ�

	chronometry(foo, nullptr); // ok.
}
