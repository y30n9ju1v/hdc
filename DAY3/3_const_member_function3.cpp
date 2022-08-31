#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// �ٽ� : ��� ��� �Լ��� Ư¡

	void print() const 
	{		
//		x = 10;			// error. 1. ��� ����Ÿ ���� �Ҽ� �����ϴ�.

//		set(10, 20);	// error. 2. ��� ��� �Լ� �ȿ�����
						//			 ��� ��� �Լ� �� ȣ�Ⱑ���մϴ�.


		// �Ʒ� ĳ������ �ǹ� ���� ĳ�����ε�, �������� ������!!
//		int* p = reinterpret_cast<int*>(this);
						// const Point* => int* ��ȯ �ε�
						//				const �Ӽ��� ���� �Ҽ� �����ϴ�.
		
		const int* p = reinterpret_cast<const int*>(this);
						// const Point* => const int* �̹Ƿ� ok

		// 3. ��� ��� �Լ������� "this" ��ü�� "����� ����Ű�� ������ �Դϴ�.
		// void print()       : void print(Point* this)
		// void print() const : void print(const Point* this)

		std::cout << x << ", " << y << std::endl;
	}

	// 4. �����̸��� ��� �Լ��� ��� ��� �Լ�/���� ��� �Լ� ������������
	void print() { std::cout << "non const member function" << std::endl; }
};

int main()
{
	Point pt(1, 2);			// pt�� ��� ��ü �ƴ�
	pt.print();				// 1. print() ������ ������ ���, ������
							// 2. print() const ������ ���

	const Point cp(1, 2);	// cp�� ��� ��ü �̹Ƿ�
	cp.print();				// print() const ������ ȣ�� ����
							// => const ������ ������ ����
}


