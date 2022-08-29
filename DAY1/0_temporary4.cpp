#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
//==========================================
void f1(Point  pt) {} // call by value     : 복사본 생성
void f2(Point& pt) {} // call by reference : 복사본 생성 안됨.

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
	return pt;	// pt자체가 반환되는 것이 아니라
				// 복사본 임시객체를 만들어서 
				// 반환 합니다
				// 리턴용 임시객체는 
				// 함수 호출문장의 끝에서 파괴 됩니다.
}
Point& f2()	// return by reference - 임시객체 생성 안됨.
{	
	return pt;	// pt자체(별명)으로 반환
}

int main()
{
	f1().x = 10; // error. 임시객체.x = 10 인데
					// tempoarary 는 rvalue.. 이므로 
					// =이 왼쪽에 놓일수 없다.
	f2().x = 10; // ok.

}



// F.43: Never (directly or indirectly) return a pointer or a reference to a local object