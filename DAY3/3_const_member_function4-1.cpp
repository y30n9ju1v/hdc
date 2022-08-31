#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;

	// ��������� ���� "���ڿ� ĳ��" ����
	mutable char cache[32];
	mutable bool cache_valid = false;
		// mutable member data
		// => ��� ��� �Լ������� ����� ���� �����Ҽ� �ְ� �ش޶�� �ǹ�

public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// toString()�� ��ü�� ���´� x, y �� �������� �����Ƿ�
	// => ��� ��� �Լ��� �Ǿ�� �մϴ�.
	// 
	// �׷���, ��ũ��(ĳ��) ������ ���(cache) �� ����Ǿ�� �մϴ�.
	const char* toString() const
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y); // cache update

			cache_valid = true;
		}
		return cache;
	}
	void set(int a, int b)
	{
		x = a;
		y = b;
		cache_valid = false;
	}
};
int main()
{
	Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}

