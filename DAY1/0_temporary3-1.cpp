#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

//void f0(Point pt) {}   // call by value : ���纻 �������..
						// ���� ���� �ڵ�.. ���� ����..

void f1(Point& pt) {}       // �ǵ� : ���ڷ� ���޵� ��ü��
							//		 �����ϰڴٴ°�
							//		 in/out parameter

void f2(const Point& pt) {}	// �ǵ� : ���ڷ� ���޵� ��ü�� �������� �ʰڴ�
							//		 in parameter

int main()
{
	f1(Point(1, 2)); // ��ü�� �����ϴ� �Լ��� �ӽð�ü�� �����ϴ°���
					// �߸��Ǿ��ٰ� ���� �ߴ�.
					// �׷��� "Point& pt = �ӽð�ü" �� ���������� ����

	f2(Point(1, 2));// �б⸸ �ϴ� �Լ��� �ӽð�ü�� �����ϴ� ���� 
					// �������� Ʋ���� �ʴ�.
					// "const Point& pt = "�ӽð�ü" �� �����ƴ�.

	std::cout << "-----" << std::endl;
}





