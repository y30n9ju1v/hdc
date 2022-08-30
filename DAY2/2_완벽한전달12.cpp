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

	// vector 에 Point 객체를 넣는 방법
	// 1. 객체를 생성한후 넣기
	Point pt(0, 0);
	v.push_back(pt);

	std::cout << "------------" << std::endl;
}