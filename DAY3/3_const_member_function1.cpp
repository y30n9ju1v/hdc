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
	// 1. 컴파일러는 항상 함수의 선언부만 보고, 함수의 호출가능 여부를 판단
	
	// 2. "void print()" 처럼 만들면 컴파일러는 멤버데이타를 수정할수도 있다고 판단

	// 3. 멤버 함수가 "멤버 데이타를 수정하지 않는다면" 반드시 컴파일러에게
	//	  알려 주어야 합니다.
	//    => "상수 멤버 함수" 라는 문법
	//    => 왜?? 알려 주나요
	//       => 상수 객체라도 호출 가능하게 하기 위해서 입니다.

	// 핵심 : 상수 객체는 상수 멤버 함수만 호출가능합니다.
	void print() const 
	{
//		x = 10; // error. 상수 멤버 함수에서는 멤버 데이타수정 안됩니다.

		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
//	Point pt(1, 2);
	const Point pt(1, 2);	// 상수 객체 입니다.

	pt.x = 10;		// error. x 가 public 이지만 상수객체 이므로
					
	pt.set(10, 20);	// error. 

	pt.print();		// 상수 멤버 함수 라면 ok
					// 상수 멤버 함수가 아니면 error.
}


