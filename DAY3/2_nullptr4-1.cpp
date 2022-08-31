// 2_nullptr4-1 - 2�� ����
#include <iostream>

struct mynullptr_t
{
	template<typename T> operator T* () { return 0; }
};
mynullptr_t mynullptr;
//================================================

template<typename F, typename T>
decltype(auto) chronometry(F f, T arg) 
{
	return f(arg);
}

void foo(int* p) {}

int main()
{
	// �Ʒ� 2���� ��쿡 T�� �߷еǴ� ���� �����ϼ���
	chronometry(foo, 0);			// int arg = 0 ���� �߷еǴµ�
									// foo(arg) �� ����!

	chronometry(foo, mynullptr);	// mynullptr_t arg = mynullptr; ���� �߷�
									// foo(arg) �ε�, arg �� mynullptr_t Ÿ��
							// mynullptr_t Ÿ���� ��� �����ͷ� �Ͻ��� ����ȯ����
}
// nullptr �� ����
// 1. boost ���̺귯������ ��ó�� ���� ����߽��ϴ�.
// 2. C++11 �� ����鼭�� nullptr ��  "Ű����"�� �Ǿ�����, ������ ���� �����մϴ�.