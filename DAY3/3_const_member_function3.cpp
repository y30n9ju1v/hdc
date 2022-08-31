#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// 핵심 : 상수 멤버 함수의 특징

	void print() const 
	{		
//		x = 10;			// error. 1. 멤버 데이타 수정 할수 없습니다.

//		set(10, 20);	// error. 2. 상수 멤버 함수 안에서는
						//			 상수 멤버 함수 만 호출가능합니다.


		// 아래 캐스팅은 의미 없는 캐스팅인데, 문법설명 때문에!!
//		int* p = reinterpret_cast<int*>(this);
						// const Point* => int* 변환 인데
						//				const 속성을 제거 할수 없습니다.
		
		const int* p = reinterpret_cast<const int*>(this);
						// const Point* => const int* 이므로 ok

		// 3. 상수 멤버 함수에서는 "this" 자체가 "상수를 가리키는 포인터 입니다.
		// void print()       : void print(Point* this)
		// void print() const : void print(const Point* this)

		std::cout << x << ", " << y << std::endl;
	}

	// 4. 동일이름의 멤버 함수를 상수 멤버 함수/비상수 멤버 함수 동시제공가능
	void print() { std::cout << "non const member function" << std::endl; }
};

int main()
{
	Point pt(1, 2);			// pt는 상수 개체 아님
	pt.print();				// 1. print() 버전이 있으면 사용, 없으면
							// 2. print() const 버전을 사용

	const Point cp(1, 2);	// cp는 상수 객체 이므로
	cp.print();				// print() const 버전만 호출 가능
							// => const 버전이 없으면 에러
}


