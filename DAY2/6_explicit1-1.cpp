// C46.���ڰ� �Ѱ��� �����ڴ� explicit �� �ϴ� ���� ����.

class Vector
{
public:
	// ���ڰ� �Ѱ��� �����ڴ� �ǵ��� �̸�"���� �ʱ�ȭ"�� �����ϴ� ���� �����ϴ�.
	
	// explicit ������ : ���� �ʱ�ȭ�� ����Ҽ� ����, ���� �ʱ�ȭ�� ����
	explicit Vector(int sz) {}
};

void fn(Vector v) {}	

int main()
{
	Vector v1(10);	
	Vector v2 = 10;		// error

	// C++11
	Vector v3{ 10 };    
	Vector v4 = { 10 }; // error

	fn(10);	// error
	fn(v1); // ok. Vector(int) �� �ƴ� ���� ������ ȣ�� �Դϴ�.
}

