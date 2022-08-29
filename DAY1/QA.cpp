
class Point
{
public:
	int x;
	int y;
};
int main()
{
	// lvalue : �̸��� �ְ�, �������忡�� ��밡��.
	// rvalue : �̸��� ����, ���� ���忡���� ��밡��

	Point pt;
	pt.x = 10; // ok. lvalue

	Point().x = 10; // error.  Point()�� rvalue

	Point&& r = Point();
	r.x = 10;		// r�� lvalue ? rvalue
					// r�� �и� �̸��� �ְ�, �������忡�� ��밡���մϴ�.
					// lvalue �Դϴ�. �׷��� ��ȣ�� ���ʿ� �ü� �ֽ��ϴ�.
}
/*
// �ӽ� ��ü�� ���ʿ� �� �� ���ٰ� �ϼ̴µ���, 
// nullptr �������� ���� �����ΰ���?
Cat(Cat&& c)
{
	c.name = nullptr;
}
Cat c = fn(); // �ӽð�ü�̹Ƿ� move �� ȣ��
			  // move�� ������ �̸��� ����� �˴ϴ�.(c)
				// c�� lvalue �Դϴ�.
*/