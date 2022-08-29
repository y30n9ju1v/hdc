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
	// goo �� 3�� ������ �ͽ��ϴ�.
	int n = 3;
	goo(n);		// 3�� ������ ��Ƽ� ������ ������
	goo(3);		// ������ �ƴ� �� "3"�� ���� ������ �˴ϴ�.
	//==========================================
	// foo ���� 1, 2 �� ���� Point �� ������ �ͽ��ϴ�.
//	Point pt(1, 2);
//	foo(pt);		// pt�� ���ڷθ� ���ȴٸ�
					// �Լ� ȣ��ڿ��� ���̻� �ʿ� �����ϴ�.
					// �׷���, ��� �ı� ���� �ʰ�, {}�� ����� �ı��˴ϴ�.

	// �Լ��� �����ϱ� ���� ��ü�� �ʿ��ϸ�, �ӽð�ü�� �����ϴ�.
	foo(Point(1, 2));

	std::cout << "-----" << std::endl;
}





