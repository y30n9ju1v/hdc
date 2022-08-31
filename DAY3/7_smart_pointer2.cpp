// R.22 : Use make_shared() to make shared_ptrs
// R.23 : Use make_unique() to make unique_ptrs

#include <iostream>
#include <memory>

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x;
	int y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 아래 코드를 new를 2번 사용합니다.
	// 1. new Point(1,2) 라는 사용자가 만든 코드
	// 2. shared_ptr 생성자 안에서 "관리 객체" 생성
//	std::shared_ptr<Point> sp1(new Point(1, 2));

	
	// 아래 코드에는 사용자가 직접 "new Point" 하는 코드가 없습니다.

	// make_shared 가 
	// 1. sizeof(Point) + sizeof(관리객체) 의 크기를 한번에 할당합니다.
	//    보다 효율적인 메모리 관리가 가능합니다.
	std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);

	// 스마트 포인터 :소멸자에서 자동으로 delete 를 책임지는 클래스.
}

