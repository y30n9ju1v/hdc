#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	
	// C80. 아무 일도 하지 않은 디폴트 생성자 가 필요 하면
	// => "= default" 로 만드는 것이 좋다.
//	Point() {}			// Bad
	Point() = default;	// Good
};

int main()
{
	Point p1;
	Point p2(1, 2);
}