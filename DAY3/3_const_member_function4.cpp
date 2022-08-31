#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ��ü�� ���¸� "���ڿ�"�� ��ȯ�ϴ� ��� �Լ�
	// => java, C#, python ��� ���� �θ� ���Ǵ� ���
	// => �������� �뵵

	// �ٽ� 1. toString() �� ���������� x, y �� �������� �ʰ�
	//        ��� ��ü�� ȣ�� �����ؾ� �մϴ�.
	// => ��� ��� �Լ��� �ϴ� ���� �½��ϴ�.
	const char* toString() const
	{
		static char s[32];
		sprintf(s, "%d, %d", x, y);
		return s;
	}
};

int main()
{
	const Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}

