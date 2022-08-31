#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)
bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	// 1. �־��� �������� ù��° ������ "3"�� ã�ƶ�
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// 2. �־��� �������� ù��° ������ "3�� ���"�� ã�ƶ�
	auto ret2 = std::find_if(v.begin(), v.end(), foo);

	std::cout << *ret2 << std::endl; // 6


	// 3. �־��� �������� ù��° ������ "k�� ���"�� ã�ƶ�
	int k = 3;
	std::cin >> k;
	auto ret2 = std::find_if(v.begin(), v.end(), ???);

}
// �ϱ� ��ü
// => �Լ� ���ڷ� ���� ������ ��ü
// => C/C++ ���� �Լ��� ���ڷ� ���� �����մϴ�
// => �׷���, "�Լ��� �ϱް�ü" ��� ǥ���մϴ�.

// Closure - ��� ���� ����ϴ� ���
// => ���ƿ� ���Ե� ���������� ĸ�� �Ҽ� �ִ� �ϱ� ��ü
// => "k + �Լ�" �� ���ڷ� ������ �ʹٴ� �ǹ�