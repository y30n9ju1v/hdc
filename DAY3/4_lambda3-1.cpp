#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{
	auto f = [](int a, int b) { return a + b; };
			 // class xxx{ operator(); }; xxx();

//	auto&       f1 = [](int a, int b) { return a + b; }; // error
//	const auto& f2 = [](int a, int b) { return a + b; }; // ok

	// �ٽ� 1. ����ǥ������ ���� ����� "�ӽð�ü(rvalue)" �Դϴ�.
	
	// �ٽ� 2. ��� ���� ǥ������ �ٸ� Ÿ�� �Դϴ�.

	auto f1 = [](int a, int b) { return a + b; };
				// class xxxx{}; xxxx();

	auto f2 = [](int a, int b) { return a + b; };
				// class yyyy{}; yyyy();

	// f1, f2�� ���� Ÿ���ϱ�� ?? �ٸ� Ÿ�� �ϱ�� ?
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
}