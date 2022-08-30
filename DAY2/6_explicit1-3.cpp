#include <iostream>

class vector
{
public:
	explicit vector(int sz) { std::cout << "vector(int)" << std::endl; }

	vector(std::initializer_list<int> e) 
	{
		std::cout << "vector(std::initializer_list)" << std::endl; 
	}
};

int main()
{
	vector v1( 10 );
	vector v2{ 10 }; // 1. vector(std::initializer_list)�� ���� ȣ��, ������
					 // 2. vector(int) ���

//	vector v3 = 10; // error. explicit vector(int) �̹Ƿ�
	vector v4 = { 10 }; // ok.. std::initializer_list ������ explicit �ƴ�

	// �� initializer_list �� ���ڷ� �޳��� ?
	// => std::initializer_list �� ���ڷ� ������ ��� ���ް����մϴ�.
	vector v5{ 1,2,3,4,5,6,7,8,9,10 };
	vector v6 = { 1,2,3,4,5,6,7,8,9,10 };

	// �Ʒ� 2���� �������� �����ϴ� ���� ���� �߿� �մϴ�.
	std::vector<int> v7(10, 3); // 10���� 3����
	std::vector<int> v8{10, 3}; // 2���� 10, 3 ���� 
}