
class Point
{
public:
	int x;
	int y;
};
int main()
{
	// lvalue : 이름이 있고, 여러문장에서 사용가능.
	// rvalue : 이름이 없고, 단일 문장에서만 사용가능

	Point pt;
	pt.x = 10; // ok. lvalue

	Point().x = 10; // error.  Point()는 rvalue

	Point&& r = Point();
	r.x = 10;		// r은 lvalue ? rvalue
					// r은 분명 이름이 있고, 여러문장에서 사용가능합니다.
					// lvalue 입니다. 그래서 등호의 왼쪽에 올수 있습니다.
}
/*
// 임시 객체는 왼쪽에 갈 수 없다고 하셨는데요, 
// nullptr 지정해줄 때는 예외인가요?
Cat(Cat&& c)
{
	c.name = nullptr;
}
Cat c = fn(); // 임시객체이므로 move 를 호출
			  // move가 받을때 이름이 생기게 됩니다.(c)
				// c는 lvalue 입니다.
*/