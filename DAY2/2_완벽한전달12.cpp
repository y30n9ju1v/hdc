#include <iostream>
#include <vector>

struct Point
{
	int x, y;

	Point(int a, int b) :x(a), y(b) { std::cout << "Point()" << std::endl;}
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	std::vector<Point> v;

	// vector 에 Point 객체를 넣는 방법
	// 방법 1. 객체를 생성한후 넣기
//	Point pt(0, 0);
//	v.push_back(pt);	// pt를 복사해서 
						// 생성된 객체를 v가 보관

	// 방법 2. 임시객체 형태로 넣기
	// 1. 임시객체를 생성할때 생성자
	// 2. 임시객체를 move 해서 생성한 객체를 v가 보관
	// 3. 임시객체이므로 push_back 종료후 즉시 파괴
//	v.push_back(Point(0, 0));


	// 방법3. 핵심!!!!
	// => 객체를 전달하지 말고, 
	//    객체를 생성하기 위한 생성자 인자를 전달.

	v.emplace_back(0, 0); // emplace_back() 함수가 내부적으로
						  // new Point( 0, 0 ) 수행

						  // => new Point(전달받은 인자들사용)
							
						  // 결국 "emplace_back" 인 자신이 받은 인자를
						  // Point 생성자에 "완벽한 전달" 하는 것입니다.
							
	                      // "완벽한 전달" 기술이 있기 때문에 가능한 함수입니다.

						
	// 핵심: STL 컨테이너에 사용자 정의 타입을 "값"으로 보관 한다면
	// "push_xxx()" 대신 "emplace_xxx()" 를 사용하라!

	// 단, 컨테이너가 primitive type(int) 또는 "포인터"를 보관한다면
	// 그냥, push_xxx() 하시면 됩니다.

	std::cout << "------------" << std::endl;
}