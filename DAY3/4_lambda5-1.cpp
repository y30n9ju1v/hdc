#include <iostream>

// �ٽ� 1. ����ǥ������ auto ������ ��� ���� global ������ �����մϴ�.
auto add = [](int a, int b) {return a + b; }; 


template<typename T>
void foo(T f)
{
//  decltype(f) f2; // xxx f2;
					// => C++20 ���� ����. C++17 ������ ����
					// => ����ǥ������ ���� �����Ϸ��� ����� Ŭ������
					//    ����Ʈ ������ ����.

	decltype(f) f2(f); // ok.. ���� �����ڴ� �ֽ��ϴ�.

}

int main()
{
	auto f = [](int a, int b) {return a + b; };
			// class xxx{}; xxx();		
			// => main �Լ� �ȿ��� Ŭ������ �����Ȱ�
	foo(f);

}