// C46.���ڰ� �Ѱ��� �����ڴ� explicit �� �ϴ� ���� ����.

class Vector
{
public:
	Vector(int sz) {}
};

//void fn(Vector v) {}	// Vector v = 10;
void fn(const Vector& v) {}	// ���ڵ�� 10�� ������ �ֽ��ϴ�.

int main()
{
	// �ٽ� 1. ��� �˾� �μ���
	// ������ ���ڷ� int �� �Ѱ� ������ �Ʒ�ó�� 4���� ���·� ��ü������ �˴ϴ�.
	// C++98
	Vector v1(10);	// direct(����) initialization : =�� ���� ���
	Vector v2 = 10; // copy(����)   initialization : =�� �ִ� ���

	// C++11
	Vector v3{ 10 };    // direct(����) initialization : =�� ���� ���
	Vector v4 = { 10 }; // copy(����)   initialization : =�� �ִ� ���

	// �ٽ� 2. �Լ��� ���� ������ "���� �ʱ�ȭ" �Դϴ�.
	fn(10);	// �ǹ̻� �߸��� �ڵ� �Դϴ�. ���������°��� �����ϴ�.
	fn(v1);
}

