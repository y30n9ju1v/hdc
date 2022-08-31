// 2_nullptr4-1 - 2�� ����
#include <iostream>

struct mynullptr_t
{
	template<typename T> operator T* () { return 0; }
};
mynullptr_t mynullptr;

template<typename F, typename T>
decltype(auto) chronometry(F f, T arg) 
{
	return f(arg);
}

void foo(int* p) {}

int main()
{
	// �Ʒ� 2���� ��쿡 T�� �߷еǴ� ���� �����ϼ���
	chronometry(foo, 0);
	chronometry(foo, mynullptr);
}
