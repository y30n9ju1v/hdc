#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }

	void set(int a, int b) { x = a; y = b; }
};
// �ٽ� : temporary �� Ư¡
int main()
{
	Point pt(1, 2);
	
	pt.x = 10;			// ok
	Point(1, 2).x = 10;	// error. 
						// => temporary �� ��ȣ�� ���ʿ� �ü� ����.
						// => ����, "rvalue" ��� �մϴ�.

	Point(1, 2).set(10, 20); // ok. ��, �ӽð�ü�� ����ΰ��� �ƴմϴ�.
							 // => ����, ������ ��ȣ�� ���ʿ� �ü� ���°�

	Point* p1 = &pt;			// ok
	Point* p2 = &Point(1, 2);	// error.
								// => tempoarary �� �ּҿ����ڷ�
								//    �ּҸ� ���Ҽ� ����.
	

	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error
								// => temporary �� reference��
								//    ����ų�� ����.
	//==================================================
	const Point& r3 = Point(1, 2);  // ok.. �ٽ�
									// const reference��
									// temporary �� ����ų�� �ִ�.
	r3.x = 10; // error. ������ "��� ����" �̹Ƿ� ��ü�� 
				// ���� ������ �ȵ˴ϴ�.
	
	//===============================
	// C++11 ���鶧 temporary �� ������ ����Ű�� ���¸� �����ϰ� �;����ϴ�.
	// "move�� �Ϻ��� ����"�� ����� ����
	Point&& r4 = Point(1, 2); // ����� ���� temporary ����Ű��!
	r4.x = 10;				  // ok..

	Point&& r5 = pt; // error. rvalue reference �� rvalue �� ����ŵ�ϴ�.
					 // lvalue(�̸��ִ� ��ü) �� ����ų�� �����ϴ�.

}







