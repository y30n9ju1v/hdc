#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		int cnt = 0;
		try
		{
			for (int i = 0; i < size; i++)
			{
				new(&buff[i]) T(value);
				++cnt;
			}
		}
		catch (...)
		{
			// ������ ȣ�⿡ �����ߴ� ��ü���� �Ҹ��� ȣ��
			for (int i = 0; i < cnt; i++)
				buff[i].~T();

			operator delete(buff);
			size = 0;
			capacity = 0;
		}
	}
	~vector()
	{
		// ������ ȣ�⿡ �����ߴ� ��ü���� �Ҹ��� ȣ��
		for (int i = 0; i < size; i++)
			buff[i].~T();

		operator delete(buff);
		size = 0;
		capacity = 0;
	}
};
int main()
{
	vector<Point> v(10, Point(0, 0));

}