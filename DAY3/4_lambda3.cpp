#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{
	// C++�� �Լ� �ȿ��� �Լ� ����� �����ϴ�.
//	int add(int a, int b) { return a + b; }; // error

	// �׷���, �Լ� �ȿ��� ����ü(�Լ���ü)�� ����� �ֽ��ϴ�.
	struct plus {}; // ok

	// �׷��� ���� ǥ���ĵ� �Լ� �ȿ��� �˴ϴ�.

	// ����ǥ���� 
	// 1. �����Ϸ��� ()�����ڰ� �����ǵ� Ŭ���� ����
	// 2. ������ Ŭ������ �ӽð�ü�� ����� �ڵ�
	
	// ���� ǥ������ auto ������ ������ �Լ� ó�� ��밡�� �մϴ�.
	// => main �Լ� �ȿ��� ���ο� �Լ��� ����Ͱ� ���� �ǹ�(local function)
	auto f = [](int a, int b) { return a + b; };
	      // class xxx{ operator(); }; xxx(); 
	
	int n1 = f(1, 2);

}