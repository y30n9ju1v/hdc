// 1_move0-1
#include <iostream>

class Point {};

// reference 와 overloading 규칙
void fn(Point& p)       { std::cout << "Point&" << std::endl; }		 // 1
void fn(const Point& p) { std::cout << "const Point&" << std::endl; }// 2
void fn(Point&& p)		{ std::cout << "Point&&" << std::endl; }	 // 3

int main()
{
	Point pt;

	fn(pt); // lvalue
			// 1번 호출, 1번이 없으면 2번 호출

	fn(Point());	// rvalue(temporary)
					// 3번호출, 3번이 없으면 2번 호출

	// lvalue 와 rvalue 를 모두 받고 싶다. : const Point&
	// lvalue 와 rvalue 를 따로 처리하고 싶다. : Point&, Point&& 2개함수제공
}