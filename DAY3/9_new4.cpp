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

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz) : size(sz), capacity(sz)
	{
		buff = new T;
	}
	~vector()
	{

	}
};

int main()
{
	vector<Point> v(10);

}