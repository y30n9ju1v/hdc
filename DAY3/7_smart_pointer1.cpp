// R.22 : Use make_shared() to make shared_ptrs
// R.23 : Use make_unique() to make unique_ptrs

#include <iostream>
#include <memory>

struct Point
{
	int x;
	int y;
	
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 핵심 1. 모든 C++ 표준 스마트 포인터의 생성자는 explicit 입니다.
	// => 직접 초기화만 가능하고 복사 초기화(=) 안됨
//	std::shared_ptr<Point> sp1 = new Point(1, 2); // error
	

	// 2. 스마트 포인터 만들때 make_shared 로 만드세요
	std::shared_ptr<Point> sp2(new Point(1, 2));  // ok. bad

	std::shared_ptr<Point> sp3 = std::make_shared<Point>(1, 2); // good
								// 1. new Point(1,2) 객체를 생성하고
								// 2. 생성된 객체를 위한 스마트 포인터를
								//	  만들어서 반환해 달라.
}






