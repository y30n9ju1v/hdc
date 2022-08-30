class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	// ���ڰ� ���ų�, ���ڰ� 2�� �̻��� ��쵵 explicit ���ϼ� �ֽ��ϴ�.
	// => ���� �ʱ�ȭ�� �ȵ˴ϴ�.
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


