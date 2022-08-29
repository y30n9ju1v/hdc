#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

void goo(int arg) {}

void foo(const Point& pt) {}

int main()
{
	// goo 에 3을 보내고 싶습니다.
	int n = 3;
	goo(n);		// 3을 변수에 담아서 보내도 되지만
	goo(3);		// 변수가 아닌 값 "3"을 직접 보내도 됩니다.
	//==========================================
	// foo 에서 1, 2 를 담은 Point 를 보내고 싶습니다.
//	Point pt(1, 2);
//	foo(pt);		// pt가 인자로만 사용된다면
					// 함수 호출뒤에는 더이상 필요 없습니다.
					// 그런데, 즉시 파괴 되지 않고, {}을 벗어날때 파괴됩니다.

	// 함수에 전달하기 위한 객체가 필요하면, 임시객체가 좋습니다.
	foo(Point(1, 2));

	std::cout << "-----" << std::endl;
}





