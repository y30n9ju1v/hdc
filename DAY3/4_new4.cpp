#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point �� ����Ʈ �����ڰ� �����ϴ�.
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// �����̳� ���鶧, ������ Ÿ�Կ� ���� �䱸������
// 1. "����Ʈ �����ڰ� �־�� �Ѵ�" ��� ���� ����
// 2. "���� �����ڰ� �־�� �Ѵ�" ��� ����.
// => �ּ��� ������ �䱸�ϴ� ���� ����.
// => "Generic Container Idioms" ��� �̸��� ���� ����
// => "STL ����� ������ ö��"


// STL vector �� ������ ������ ���ô�.
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
//		buff = new T[size]; // �̷��� �ϸ� T�� �ݵ�� "����Ʈ �����ڰ� �־�� �Ѵ�"
					        // �� ���������� ������ �˴ϴ�.

		// �׷���, ���� vector�� �Ʒ� ó�� �����Ǿ� �ֽ��ϴ�.
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
//			new(&buff[i]) T;		// �� �ڵ�� ����Ʈ ������ ȣ��.
			new(&buff[i]) T(value); // �� �ڵ�� ���� ������ ȣ��.
		}
	}
	~vector()
	{

	}
};
int main()
{
//	vector<Point> v(10); // error
	vector<Point> v(10, Point(0,0)); // ����Ʈ �����ڰ� ���� Ÿ���� �����Ҷ���
									// �ݵ��, �ʱ�ȭ�� ����� ��ü ����

}