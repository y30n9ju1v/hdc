#include <iostream>

// C.47: Define and initialize member variables 
//       in the order of member declaration

// �Ʒ� Ŭ������ � ������ ������� ?
struct vector
{
	int* buff;
	int size;
public:
	// "��� �ʱ�ȭ ����Ʈ"�� ��������� �̹� �����Ǿ� �ֽ��ϴ�.
	// 1. ��� Ŭ������ �ִٸ� ��� Ŭ���� ������
	// 2. ��� ����Ÿ�� "��� ����Ÿ�� ���� ����" ��� ����
	// => buff �� ���� ����Ǿ����Ƿ� ���� ����˴ϴ�.
	//				 (2)		(1)
//	vector(int sz) : size(sz), buff(new int[size]) // new �Ҷ� size �ʱ�ȭ�ȵ�

	vector(int sz) : buff(new int[sz]), size(sz)  // ���ڵ尡 ���� �ڵ�
	{
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector v(10);
}