struct Point
{
	int x;
	int y;
};

int main()
{
	Point pt;

	// ��Ģ 1. lvalue reference �� lvalue �� ����Ų��.
	// => lvalue(�̸� �ִ� ��ü)
	// => rvalue(�̸� ���� ��ü, temporary)
	Point& r1 = pt;		// ok 
	Point& r2 = Point();// error

	// ��Ģ 2. const lvalue reference �� lvalue, rvalue ��� ����Ų��
	const Point& r3 = pt;		// ok 
	const Point& r4 = Point();	// ok

	
	// ��Ģ 3. rvalue reference �� rvalue �� ����Ų��. - C++11
	Point&& r5 = pt;		// error 
	Point&& r6 = Point();	// ok


	// ��Ģ4. const rvalue reference �� rvalue �� - �߿������� ����
	const Point&& r7 = pt;		// error 
	const Point&& r8 = Point();	// ok

}