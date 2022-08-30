#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� : Point �� ����Ʈ �����ڰ� ���ٴ� ���Դϴ�.
//	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};


class Rect
{
	Point ptFrom;
	Point ptTo;
public:
	// �ٽ� : ����Ʈ �����ڰ� ���� Ÿ���� �������Ÿ�� �ִ� ���, �ݵ�� 
	//       ����� �����ڸ� ���� ȣ���ؾ� �մϴ�.
	//		// �����Ϸ��� �߰��� �ڵ�
//	Rect()	// : ptFrom(), ptTo()

	Rect() : ptFrom(0, 0), ptTo(0, 0) // C++98 ���� �ذ�å
	{
		std::cout << "Rect()" << std::endl;
	}
};

class Rect2
{
	Point ptFrom{0,0};	// C++11 ���ʹ� �̷��� �ص� �˴ϴ�. 
	Point ptTo{0,0};	// ���⿡ �ۼ��ص�, �ᱹ, ���� Rect �� ������ ���� �Դϴ�.
						// �� �κ��� �������� "Rect() : ptFrom(0,0)" ó������°�
//	Point ptTo(0,0); // () �� �ȵ˴ϴ�. {} �� ����

public:
	Rect() // : ptFrom(0, 0), ptTo(0, 0) 
	{
		std::cout << "Rect()" << std::endl;
	}
};



int main()
{
	Rect r;
}




