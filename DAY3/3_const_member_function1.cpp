// Con.1 : By default, make objects immutable
// Con.2 : "By default, make member functions const"
// Con.3 : By default, pass pointersand references to consts

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }
	// 1. �����Ϸ��� �׻� �Լ��� ����θ� ����, �Լ��� ȣ�Ⱑ�� ���θ� �Ǵ�
	
	// 2. "void print()" ó�� ����� �����Ϸ��� �������Ÿ�� �����Ҽ��� �ִٰ� �Ǵ�

	// 3. ��� �Լ��� "��� ����Ÿ�� �������� �ʴ´ٸ�" �ݵ�� �����Ϸ�����
	//	  �˷� �־�� �մϴ�.
	//    => "��� ��� �Լ�" ��� ����
	//    => ��?? �˷� �ֳ���
	//       => ��� ��ü�� ȣ�� �����ϰ� �ϱ� ���ؼ� �Դϴ�.

	// �ٽ� : ��� ��ü�� ��� ��� �Լ��� ȣ�Ⱑ���մϴ�.
	void print() const 
	{
//		x = 10; // error. ��� ��� �Լ������� ��� ����Ÿ���� �ȵ˴ϴ�.

		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
//	Point pt(1, 2);
	const Point pt(1, 2);	// ��� ��ü �Դϴ�.

	pt.x = 10;		// error. x �� public ������ �����ü �̹Ƿ�
					
	pt.set(10, 20);	// error. 

	pt.print();		// ��� ��� �Լ� ��� ok
					// ��� ��� �Լ��� �ƴϸ� error.
}


