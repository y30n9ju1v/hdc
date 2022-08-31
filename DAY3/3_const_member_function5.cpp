#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] 연산자를 재정의하면 객체를 배열처럼 사용가능합니다.

	// 핵심 1. [] 연산자호출은 등호의 왼쪽에도 놓일수 있어야 합니다.
	//         => reference 를 반환해야 합니다.
	T& operator[](int idx) { return buff[idx]; }
};
int main()
{
	vector<int> v(10);

	v[0] = 0;		// v.operator[](0) = 0;
	int a = v[0];
}