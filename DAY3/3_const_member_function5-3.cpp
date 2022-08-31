#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// ��� 2. ��� ����Լ��� ���� ��� �Լ� �� ���� �����Ѵ�.
	T& operator[](int idx)       { return buff[idx]; }


	// ��� ��� �Լ� ������ "v[0] = 10" �� ����Ҽ� ���� �ؾ� �մϴ�.

	// 1. T& �� �ƴ� T�� ��ȯ����.
	// => ���� ���� rvalue �̴�.
//	T operator[](int idx) const { return buff[idx]; }

	// 2. const T& �� ��ȯ ����
	// => lvalue �� ��ȯ �ȴ�. ��, const ������ ��ȣ�� ���ʿ� �ü� ����.
	const T& operator[](int idx) const { return buff[idx]; }
};

int main()
{
	      vector<int> v1(10);
	const vector<int> v2(10);

	int n1;

	//			// ���ϴ� ��		���� ����
	v1[0] = 10;	// O			O
	n1 = v1[0]; // O			O

	v2[0] = 10; // X			X
	n1 = v2[0]; // O			O


	auto p = &v2[0];	// �Ǿ� �ұ��? �ȵǰ� �ұ�� ?
						// �Ǿ� �մϴ�.
						// rvalue �� �ּҸ� ���Ҽ� �����ϴ�.
						// lvalue �� �ּҸ� ���Ҽ� �ֽ��ϴ�.
}