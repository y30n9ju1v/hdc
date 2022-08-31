#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// new�� �ϴ� ��
	// 1. �޸� �Ҵ�
	// 2. ������ ȣ��
//	Point* p1 = new Point(1, 2);

	// 1. �Ҹ��� ȣ��
	// 2. �޸� ���� 
//	delete p1;

	// 1. �޸𸮸� �Ҵ��ϱ� ( C�� malloc �� ���� )
	// => void* ��ȯ�̹Ƿ� ĳ���� �ʿ�
	Point* p2 = static_cast<Point*>( operator new( sizeof(Point) ) );

	// 2. �̹� �Ҵ�� �޸𸮿� ������ ȣ��
	new(p2) Point(1, 2); // p2��� �޸� �ּҿ� �ִ� ��ü�� ������ ȣ��
						 // "placement new" ��� �Ҹ��� ���
//	std::construct_at(p2, 1, 2); // C++20 ���� ����
	

	// 3. �޸� ���� ���� �Ҹ��ڸ� ȣ��
//	p2->~Point();        // C++98 ���� ���� ���Ǵ� ǥ���
	std::destroy_at(p2); // C++17 ���ʹ� �� �Լ��� ����ص� �˴ϴ�.


	// 4. �޸𸮸� ���� ( C �� free�� ���� )
	operator delete(p2);
}

// malloc : �޸� �Ҵ�
// new    : ��ü ����( �޸� �Ҵ� + ������ ȣ�� )

// new      Point(1,2) : ���ο� �޸𸮿�        ��ü�� ������ �޶�
// new(�ּ�) Point(1,2) : �̹� �Ҵ�� �޸�(�ּ�)�� ��ü�� ������ �޶�
//												(������ ȣ��)	
//						 "placement new", "��ġ ���� new" ��� �մϴ�.