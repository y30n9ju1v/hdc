#include <iostream>

// 149 page

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl;}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
// �ٽ� 1. temporary �� ����� ��
//     2. ���� �� �˾� �μ���.
int main()
{
//	Point pt(1, 2); // named object
					// ���� : �ڽ��� ������ ���� ����� �ı�

//	Point (1, 2);	// unnamed object
					// temporary(�ӽð�ü) ��� �մϴ�.
					// ���� : �ڽ��� ������ ������ ��

	Point(1, 2), std::cout << "X" << std::endl; 

	std::cout << "-------" << std::endl;

} // <== pt �ı�.


  