// 1_move0-1
#include <iostream>

class Point {};

// reference �� overloading ��Ģ
void fn(Point& p)       { std::cout << "Point&" << std::endl; }		 // 1
void fn(const Point& p) { std::cout << "const Point&" << std::endl; }// 2
void fn(Point&& p)		{ std::cout << "Point&&" << std::endl; }	 // 3

int main()
{
	Point pt;

	fn(pt); // lvalue
			// 1�� ȣ��, 1���� ������ 2�� ȣ��

	fn(Point());	// rvalue(temporary)
					// 3��ȣ��, 3���� ������ 2�� ȣ��

	// lvalue �� rvalue �� ��� �ް� �ʹ�. : const Point&
	// lvalue �� rvalue �� ���� ó���ϰ� �ʹ�. : Point&, Point&& 2���Լ�����
}