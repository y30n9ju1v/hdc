#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] �����ڸ� �������ϸ� ��ü�� �迭ó�� ��밡���մϴ�.

	// �ٽ� 1. [] ������ȣ���� ��ȣ�� ���ʿ��� ���ϼ� �־�� �մϴ�.
	//         => reference �� ��ȯ�ؾ� �մϴ�.
	T& operator[](int idx) { return buff[idx]; }
};
int main()
{
	vector<int> v(10);

	v[0] = 0;		// v.operator[](0) = 0;
	int a = v[0];
}