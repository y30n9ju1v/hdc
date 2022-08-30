#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// �Ϻ��� ������ �Ϸ���
// 1. ���纻 ��ü�� ����
// 2. const �� �߰��Ǹ� �ȵȴ�.
// => int&, int&& ������ ���� �����ؾ� �Ѵ�.


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
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n);  

	std::cout << n << std::endl;
}
