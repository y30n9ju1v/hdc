#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	
	// C80. �ƹ� �ϵ� ���� ���� ����Ʈ ������ �� �ʿ� �ϸ�
	// => "= default" �� ����� ���� ����.
//	Point() {}			// Bad
	Point() = default;	// Good
};

int main()
{
	Point p1;
	Point p2(1, 2);
}