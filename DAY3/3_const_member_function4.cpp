#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 객체의 상태를 "문자열"로 반환하는 멤버 함수
	// => java, C#, python 등에서 아주 널리 사용되는 기술
	// => 디버깅등의 용도

	// 핵심 1. toString() 은 내부적으로 x, y 를 변경하지 않고
	//        상수 객체라도 호출 가능해야 합니다.
	// => 상수 멤버 함수로 하는 것이 맞습니다.
	const char* toString() const
	{
		static char s[32];
		sprintf(s, "%d, %d", x, y);
		return s;
	}
};

int main()
{
	const Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}

