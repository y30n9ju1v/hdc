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
	

}