#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
//==========================================
void f1(Point  pt) {} // call by value     : ���纻 ����
void f2(Point& pt) {} // call by reference : ���纻 ���� �ȵ�.

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}






//-----------------------------------
Point pt(1, 2);

Point f1()	// return by value
{
	return pt;	// pt��ü�� ��ȯ�Ǵ� ���� �ƴ϶�
				// ���纻 �ӽð�ü�� ���� 
				// ��ȯ �մϴ�
				// ���Ͽ� �ӽð�ü�� 
				// �Լ� ȣ�⹮���� ������ �ı� �˴ϴ�.
}
Point& f2()	// return by reference - �ӽð�ü ���� �ȵ�.
{	
	return pt;	// pt��ü(����)���� ��ȯ
}

int main()
{
	f1().x = 10; // error. �ӽð�ü.x = 10 �ε�
					// tempoarary �� rvalue.. �̹Ƿ� 
					// =�� ���ʿ� ���ϼ� ����.
	f2().x = 10; // ok.

}



// F.43: Never (directly or indirectly) return a pointer or a reference to a local object