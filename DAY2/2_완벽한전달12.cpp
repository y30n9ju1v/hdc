#include <iostream>
#include <vector>

struct Point
{
	int x, y;

	Point(int a, int b) :x(a), y(b) { std::cout << "Point()" << std::endl;}
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	std::vector<Point> v;

	// vector �� Point ��ü�� �ִ� ���
	// ��� 1. ��ü�� �������� �ֱ�
//	Point pt(0, 0);
//	v.push_back(pt);	// pt�� �����ؼ� 
						// ������ ��ü�� v�� ����

	// ��� 2. �ӽð�ü ���·� �ֱ�
	// 1. �ӽð�ü�� �����Ҷ� ������
	// 2. �ӽð�ü�� move �ؼ� ������ ��ü�� v�� ����
	// 3. �ӽð�ü�̹Ƿ� push_back ������ ��� �ı�
//	v.push_back(Point(0, 0));


	// ���3. �ٽ�!!!!
	// => ��ü�� �������� ����, 
	//    ��ü�� �����ϱ� ���� ������ ���ڸ� ����.

	v.emplace_back(0, 0); // emplace_back() �Լ��� ����������
						  // new Point( 0, 0 ) ����

						  // => new Point(���޹��� ���ڵ���)
							
						  // �ᱹ "emplace_back" �� �ڽ��� ���� ���ڸ�
						  // Point �����ڿ� "�Ϻ��� ����" �ϴ� ���Դϴ�.
							
	                      // "�Ϻ��� ����" ����� �ֱ� ������ ������ �Լ��Դϴ�.

						
	// �ٽ�: STL �����̳ʿ� ����� ���� Ÿ���� "��"���� ���� �Ѵٸ�
	// "push_xxx()" ��� "emplace_xxx()" �� ����϶�!

	// ��, �����̳ʰ� primitive type(int) �Ǵ� "������"�� �����Ѵٸ�
	// �׳�, push_xxx() �Ͻø� �˴ϴ�.

	std::cout << "------------" << std::endl;
}