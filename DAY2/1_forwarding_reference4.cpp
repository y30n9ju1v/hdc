#include <iostream>

template<typename T> void foo(T&& arg)
{
	// Ȯ���ϴ¹�
	// ������ �Լ��� �̸��� ����� ���� �˴ϴ�.
//	std::cout << __func__ << std::endl; // C++ǥ��. �Լ� �̸��� ���

	std::cout << __FUNCSIG__ << std::endl; // ���ڸ� ������ �Լ��̸�
										// ��, C++ǥ���� �ƴ�. vc������

//	std::cout << __PRETTY_FUNCTION__ << std::endl; // g++����
											// vc �ȵ�.
}

int main()
{
	int n = 10;

	foo(n);  //	T=int&    T&&=int& &&		foo(int&)
	foo(10); // T=int	  T&&=int&&         foo(int&&)
}




