#include <iostream>
// godbolt.org 에 접속해 보세요. C++ 코드의 어셈블리를 볼수 있는 사이트

struct Point
{
	int x;
	int y;

//	Point() {}			// 사용자가 만든 생성자
						// => 아무일도 하지 않지만
						// => 컴파일러는 하는일이 있다고 생각합니다.
						// => 컴파일러는 구현이 아닌 함수 선언만 보고 호출을 결정하므로

	Point() = default; // 컴파일러가 만든 생성자
};



int main()
{
	int n1;		// 쓰레기값
	int n2 = 0;	// 0 초기화   value initialization
	int n3{0};	// 0 초기화.  value initialization
	int n4{};	// 0 초기화.  default initialization

	Point p1;   // x, y 쓰레기값
	Point p2{}; // x, y 는 0으로 초기화
				// 단, 사용자가 생성자를 제공하지 않은 경우만

	std::cout << p2.x << std::endl;
}