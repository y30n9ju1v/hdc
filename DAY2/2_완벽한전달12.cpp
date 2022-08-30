#include <iostream>
#include <vector>

struct Point
{
	int x, y;

	Point(int a, int b) :x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}
	~Point() { std::cout << "~Point()" << std::endl; }
};
int main()
{
	std::vector<Point> v;

	// vector �� Point ��ü�� �ִ� ���
	// 1. ��ü�� �������� �ֱ�
	Point pt(0, 0);
	v.push_back(pt);

	std::cout << "------------" << std::endl;
}