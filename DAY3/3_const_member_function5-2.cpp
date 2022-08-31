#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }
	// 방법 1. [] 를 상수 멤버 함수로 하면 어떨까 ?
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

	// 핵심 : v2 가 상수 이고, v2가 할당한 메모리는 상수가 아니지만
	//       vector 클래스의 의도는
	//		 v2가 할당한 메모리를 상수 처럼 보이게 하고 싶은것 입니다.
}