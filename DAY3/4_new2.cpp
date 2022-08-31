#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� : Point �� ����Ʈ �����ڰ� �����ϴ�.
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};

int main()
{
	// Point ��ü�� ���� �Ѱ��� ����� ������
	Point* p1 = new Point(1, 2);

	// Point ��ü�� ���� 10�� ����� ������
//	Point* p2 = new Point[10]; // error.
						// �� ǥ����� "Point"�� ����Ʈ �����ڰ� �־�� �մϴ�.

	// C++11 ���ʹ� �Ʒ� ó���Ҽ��� �ֽ��ϴ�
	// => �׷���, ������ �������� ... ???
//	Point* p2 = new Point[10]{ {0,0},{0,0}, {0,0}, {0,0}, {0,0},
//							   {0,0},{0,0}, {0,0}, {0,0}, {0,0} };

	// �̰��, �޸� �Ҵ�� ��ü ������ ����� �ϸ� �˴ϴ�.
//	Point* p2 = new Point[10]; // "�޸��Ҵ� + ������ ȣ��" �� �Ϸ��� �ϹǷ� ����
	
	// 1. �޸𸮸� �Ҵ�
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));
	
	// 2. �Ҵ�� �޸𸮿� ��ü ����(������ ȣ��)
	for (int i = 0; i < 10; i++)
	{
//		new(�ּ�)    Point(0, 0);
		new(&p2[i]) Point(0, 0);
	}
	
	// 10�� ��ü��  �Ҹ��� ȣ����
	for (int i = 0; i < 10; i++)
		p2[i].~Point();

	// �޸� ����.
	operator delete(p2);

}