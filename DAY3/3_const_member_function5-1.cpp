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
	// �Ǿ� �ϸ� O, �ȵǾ� �ϸ� X ä�� ������
	//			// ���ϴ� ��		���� ����
	v1[0] = 10;	//
	n1 = v1[0]; //

	v2[0] = 10; //
	n1 = v2[0]; // 
}