#include <iostream>

// 149 page

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl;}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
//	Point pt(1, 2); // named object
					// 수명 : 자신을 선언한 블럭을 벗어날때 파괴

//	Point (1, 2);	// unnamed object
					// temporary(임시객체) 라고도 합니다.
					// 수명 : 자신을 선언한 문장의 끝

	Point(1, 2), std::cout << "X" << std::endl; 

	std::cout << "-------" << std::endl;
} // <== pt 파괴.


  