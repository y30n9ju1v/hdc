// QA2
#include <iostream>

void fn(int& n)  { std::cout << "int&" << std::endl; }   // 1
void fn(int&& n) { std::cout << "int&&" << std::endl; }  // 2
	// => fn(int&&) : rvalue �� �ްڴٴ� ���Դϴ�.
	//				  rvalue reference Ÿ���� �޴� ���� �ƴմϴ�.
int main()
{
	int n = 0;
	fn(n);	// n �� �̸��� �ֽ��ϴ�. lvalue �Դϴ�.		- 1��ȣ��
	fn(3);  // 3 �� �̸��� ���� ���� �ֽ��ϴ�. rvalue	- 2��ȣ��
			// rvalue �̹Ƿ� "3 = 10" �� �ȵ˴ϴ�.

	int&& r = 3;

	fn(r); // 1��ȣ��

	//		Ÿ��			value�Ӽ�
	// 3	int			rvalue
	// n	int			lvalue
	// r    int&&		lvalue

	fn(static_cast<int&&>(r)); // 2�� ȣ��
				// r�� Ÿ���� int&& �ε�, ���� Ÿ�� ĳ���� �ƴѰ��� ?
				// => �� �ڵ�� "Ÿ�� ĳ����" �� �ƴմϴ�.
				// => lvalue �� rvalue �� �����ϴ� "value ĳ����" �Դϴ�.
}