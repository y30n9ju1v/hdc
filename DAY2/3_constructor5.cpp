#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point 는 디폴트 생성자가 없다는 점입니다.
//	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};


class Rect
{
	Point ptFrom;
	Point ptTo;
public:
	// 핵심 : 디폴트 생성자가 없는 타입이 멤버데이타로 있는 경우, 반드시 
	//       멤버의 생성자를 직접 호출해야 합니다.
	//		// 컴파일러가 추가한 코드
//	Rect()	// : ptFrom(), ptTo()

	Rect() : ptFrom(0, 0), ptTo(0, 0) // C++98 시절 해결책
	{
		std::cout << "Rect()" << std::endl;
	}
};

class Rect2
{
	Point ptFrom{0,0};	// C++11 부터는 이렇게 해도 됩니다. 
	Point ptTo{0,0};	// 여기에 작성해도, 결국, 위의 Rect 와 동일한 기계어 입니다.
						// 이 부분의 내용으로 "Rect() : ptFrom(0,0)" 처럼만드는것
//	Point ptTo(0,0); // () 는 안됩니다. {} 만 가능

public:
	Rect() // : ptFrom(0, 0), ptTo(0, 0) 
	{
		std::cout << "Rect()" << std::endl;
	}
};



int main()
{
	Rect r;
}




