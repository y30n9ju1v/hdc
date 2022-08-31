#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	T& operator[](int idx) { return buff[idx]; }
};
int main()
{
	      vector<int> v1(10);  //       int v1[10]
	const vector<int> v2(10);  // const int v2[10]

	int n1;
	// 되야 하면 O, 안되야 하면 X 채워 보세요
	//			// 원하는 것		현재 상태
	v1[0] = 10;	//
	n1 = v1[0]; //

	v2[0] = 10; //
	n1 = v2[0]; // 
}