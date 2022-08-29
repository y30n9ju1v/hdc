#include <iostream>

struct Rect
{
	int left, top, right, bottom;
};

void f1(Rect& rc)       {} // 임시객체 받을수 없습니다.
void f2(const Rect& rc) {} // 임시객체 받을수 있습니다.

int main()
{
	Rect rc;
	
	f1(Rect()); // error
	f2(Rect()); // ok. 

}