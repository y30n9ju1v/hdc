#include <iostream>

struct Rect
{
	int left, top, right, bottom;
};

void f1(Rect& rc)       {} // �ӽð�ü ������ �����ϴ�.
void f2(const Rect& rc) {} // �ӽð�ü ������ �ֽ��ϴ�.

int main()
{
	Rect rc;
	
	f1(Rect()); // error
	f2(Rect()); // ok. 

}