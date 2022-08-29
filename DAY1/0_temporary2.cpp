#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }

	void set(int a, int b) { x = a; y = b; }
};
// 핵심 : temporary 의 특징
int main()
{
	Point pt(1, 2);
	
	pt.x = 10;			// ok
	Point(1, 2).x = 10;	// error. 
						// => temporary 는 등호의 왼쪽에 올수 없다.
						// => 흔히, "rvalue" 라고 합니다.

	Point(1, 2).set(10, 20); // ok. 즉, 임시객체가 상수인것은 아닙니다.
							 // => 단지, 문법상 등호의 왼쪽에 올수 없는것

	Point* p1 = &pt;			// ok
	Point* p2 = &Point(1, 2);	// error.
								// => tempoarary 는 주소연산자로
								//    주소를 구할수 없다.
	

	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error
								// => temporary 는 reference로
								//    가리킬수 없다.
	//==================================================
	const Point& r3 = Point(1, 2);  // ok.. 핵심
									// const reference는
									// temporary 를 가리킬수 있다.
	r3.x = 10; // error. 하지만 "상수 참조" 이므로 객체의 
				// 상태 변경은 안됩니다.
	
	//===============================
	// C++11 만들때 temporary 도 참조로 가리키고 상태를 변경하고 싶었습니다.
	// "move와 완벽한 전달"을 만들기 위해
	Point&& r4 = Point(1, 2); // 상수성 없이 temporary 가리키기!
	r4.x = 10;				  // ok..

	Point&& r5 = pt; // error. rvalue reference 는 rvalue 만 가리킵니다.
					 // lvalue(이름있는 객체) 는 가리킬수 없습니다.

}







