#include <iostream>
// godbolt.org �� ������ ������. C++ �ڵ��� ������� ���� �ִ� ����Ʈ

struct Point
{
	int x;
	int y;

//	Point() {}			// ����ڰ� ���� ������
						// => �ƹ��ϵ� ���� ������
						// => �����Ϸ��� �ϴ����� �ִٰ� �����մϴ�.
						// => �����Ϸ��� ������ �ƴ� �Լ� ���� ���� ȣ���� �����ϹǷ�

	Point() = default; // �����Ϸ��� ���� ������
};



int main()
{
	int n1;		// �����Ⱚ
	int n2 = 0;	// 0 �ʱ�ȭ   value initialization
	int n3{0};	// 0 �ʱ�ȭ.  value initialization
	int n4{};	// 0 �ʱ�ȭ.  default initialization

	Point p1;   // x, y �����Ⱚ
	Point p2{}; // x, y �� 0���� �ʱ�ȭ
				// ��, ����ڰ� �����ڸ� �������� ���� ��츸

	std::cout << p2.x << std::endl;
}