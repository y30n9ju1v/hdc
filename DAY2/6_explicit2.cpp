class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	// 인자가 없거나, 인자가 2개 이상인 경우도 explicit 붙일수 있습니다.
	// => 복사 초기화는 안됩니다.
	explicit Point() = default;
	explicit Point(int x, int y) : x{ x }, y{ y } {}
};
void fn(Point pt) {} 

int main()
{
	Point p1;
	Point p2 = {};		// error explicit
	Point p3 = { 1,2 };	// error explicit
	Point p4{1, 2};	// ok
	Point p5(1, 2);	// ok

	fn({});		// error explicit
	fn({1,2});	// error explicit
	
}


