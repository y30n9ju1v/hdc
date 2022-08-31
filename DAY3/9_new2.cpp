#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point 는 디폴트 생성자가 없습니다.
//	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// Point 객체를 힙에 한개만 만들어 보세요
	Point* p1 = new Point(1, 2);

	// Point 객체를 힙에 10개 만들어 보세요
	// ??	
	
}