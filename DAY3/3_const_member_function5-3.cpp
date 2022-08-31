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


	// 상수 멤버 함수 버전은 "v[0] = 10" 을 사용할수 없게 해야 합니다.

	// 1. T& 가 아닌 T를 반환하자.
	// => 리턴 값이 rvalue 이다.
//	T operator[](int idx) const { return buff[idx]; }

	// 2. const T& 를 반환 하자
	// => lvalue 가 반환 된다. 단, const 때문에 등호의 왼쪽에 올수 없다.
	const T& operator[](int idx) const { return buff[idx]; }
};

int main()
{
	      vector<int> v1(10);
	const vector<int> v2(10);

	int n1;

	//			// 원하는 것		현재 상태
	v1[0] = 10;	// O			O
	n1 = v1[0]; // O			O

	v2[0] = 10; // X			X
	n1 = v2[0]; // O			O


	auto p = &v2[0];	// 되야 할까요? 안되게 할까요 ?
						// 되야 합니다.
						// rvalue 는 주소를 구할수 없습니다.
						// lvalue 는 주소를 구할수 있습니다.
}