// 1_move0-1
#include <iostream>

class Point {};

// reference ¿Í overloading ±ÔÄ¢
void fn(Point& p)       { std::cout << "Point&" << std::endl; }
void fn(const Point& p) { std::cout << "const Point&" << std::endl; }
void fn(Point&& p)		{ std::cout << "Point&&" << std::endl; }

int main()
{
	Point pt;

	fn(pt);

	fn(Point());
}