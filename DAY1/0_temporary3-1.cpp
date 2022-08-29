#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

//void f0(Point pt) {}   // call by value : 복사본 오버헤드..
						// 좋지 않은 코드.. 오후 수업..

void f1(Point& pt) {}       // 의도 : 인자로 전달된 객체를
							//		 수정하겠다는것
							//		 in/out parameter

void f2(const Point& pt) {}	// 의도 : 인자로 전달된 객체를 수정하지 않겠다
							//		 in parameter

int main()
{
	f1(Point(1, 2)); // 객체를 수정하는 함수에 임시객체를 전달하는것은
					// 잘못되었다고 생각 했다.
					// 그래서 "Point& pt = 임시객체" 를 에러나오게 설계

	f2(Point(1, 2));// 읽기만 하는 함수에 임시객체를 전달하는 것은 
					// 논리적으로 틀리지 않다.
					// "const Point& pt = "임시객체" 는 에러아님.

	std::cout << "-----" << std::endl;
}





