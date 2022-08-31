#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// 방법 2. 상수 멤버함수와 비상수 멤버 함수 를 따로 제공한다.
	T& operator[](int idx)       { return buff[idx]; }
	T& operator[](int idx) const { return buff[idx]; }
};
int main()
{
	      vector<int> v1(10);
	const vector<int> v2(10);

	int n1;

	//			// 원하는 것		현재 상태
	v1[0] = 10;	// O			O
	n1 = v1[0]; // O			O

	v2[0] = 10; // X			O
	n1 = v2[0]; // O			O

}