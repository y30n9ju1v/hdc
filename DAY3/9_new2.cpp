#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� : Point �� ����Ʈ �����ڰ� �����ϴ�.
//	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// Point ��ü�� ���� �Ѱ��� ����� ������
	Point* p1 = new Point(1, 2);

	// Point ��ü�� ���� 10�� ����� ������
	// ??	
	
}