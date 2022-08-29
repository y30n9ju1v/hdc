// 10_복사생성자
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 사용자가 만들지 않으면 컴파일러가 아래 모양의 복사 생성자 제공
//	Point(const Point& p) : x(p.x), y(p.y) {}

	// 복사 생성자 모양을 정확히 이해해 보세요

	// 1. call by value
	// => 복사 생성자가 무한히 호출되는 표기법
	// => 컴파일 에러. 복사 생성자는 call by value 일수 없습니다.
//	Point(Point p) {} // 인자 받을때 "Point p = p2"

	// 2. call by reference
	// => 에러는 아님.
	// => rvalue(임시객체) 를 받을수 없습니다
	// => Point ret = fn(); 이 코드가 안됩니다.!!
//	Point(Point& p) {}

	// 3. call by const reference
	// => rvalue 와 lvalue 를 모두 받을수 있습니다.
	// => 그래서 복사 생성자의 모양이 아래와 같습니다.
	Point(const Point& p) : x(p.x), y(p.x) {}
};

Point fn()
{
	Point p(1, 2);
	return p;
}
int main()
{
	Point p1;		// 1번 생성자
	Point p2(1, 2); // 2번 생성자
	Point p3(p2);	// Point(Point) 필요.. 
					// => 복사 생성자 호출.
	Point p4 = fn(); // 값반환 이므로 "임시객체"
			// Point p4(fn())
}




