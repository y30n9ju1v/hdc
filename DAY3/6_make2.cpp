#include <iostream>
#include <tuple>
#include <string>
using namespace std::literals;

int main()
{
	std::pair<int, double> p1(3, 3.4);
	std::tuple<int, double, int, double> t1(3, 3.4, 3, 3.4);

	// ��ó�� pair, tuple �� ���� ����ϸ� Ÿ���� �� �����ؾ� �մϴ�.
	// make_ �Լ� ����ϼ���
	auto p2 = std::make_pair(3, 3.4);
	auto t2 = std::make_tuple(3, 3.4, 3, 3.4f, "a", "a"s);
									// const char*, std::string

	// �׷���, C++17 ���ʹ� Ŭ���� ���ø��� Ÿ���߷� �����մϴ�.

	std::tuple t3(3, 3.4, 3, 3.4); // ok. C++17 ����.
}