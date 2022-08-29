struct Point
{
	int x;
	int y;
};

int main()
{
	Point pt;

	// 규칙 1. lvalue reference 는 lvalue 만 가리킨다.
	// => lvalue(이름 있는 객체)
	// => rvalue(이름 없는 객체, temporary)
	Point& r1 = pt;		// ok 
	Point& r2 = Point();// error

	// 규칙 2. const lvalue reference 는 lvalue, rvalue 모두 가리킨다
	const Point& r3 = pt;		// ok 
	const Point& r4 = Point();	// ok

	
	// 규칙 3. rvalue reference 는 rvalue 만 가리킨다. - C++11
	Point&& r5 = pt;		// error 
	Point&& r6 = Point();	// ok


	// 규칙4. const rvalue reference 도 rvalue 만 - 중요하지는 않음
	const Point&& r7 = pt;		// error 
	const Point&& r8 = Point();	// ok

}