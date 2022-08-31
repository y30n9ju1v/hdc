#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// 아래 코드가 아주 유명한 코드 입니다. 꼭 기억해 두세요
	// stack s; s.top() 에서 top 도 아래 처럼 2개 만드는 것입니다.

	      T& operator[](int idx)       { return buff[idx]; }
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

//	v2[0] = 10; // X			X
	n1 = v2[0]; // O			O


	auto p = &v2[0];	
}
