// ��� ��� �Լ��� ������ �ƴ� "�ʼ� ����" �Դϴ�.

// ��ü�� ���¸� �������� ���� ��� ��� �Լ�(getter) ��

// "�ݵ�� ��� ��� �Լ�"�� �ؾ߸� �˴ϴ�.

// �Ʒ� getArea() �� const ������ �ʴ� ���� "Ʋ�� �ڵ�" �Դϴ�.

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};

//void foo(Rect r)		// call by value : ���纻�� �������!!!

void foo( const Rect& r)	// ���ڵ尡 ���� �ڵ�!!!
{
	int n = r.getArea(); //????
}

int main()
{
	Rect r(1, 2, 3, 4);		// �����ü �ƴմϴ�.

	int n = r.getArea();	// ok.
	
	foo(r);
}