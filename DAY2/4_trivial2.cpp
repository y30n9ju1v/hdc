#include <iostream>
#include <type_traits> 

class Test
{
//	int data;
	int data = 0; // �ʱⰪ�� �ִ� �ڵ�� �ᱹ �����ڿ��� �ϴ� ���Դϴ�.
					// ��, �� �ڵ� ������ �����ڴ� trivial ���� �ʽ��ϴ�.
public:
//	virtual void foo() {} // �����Լ��� ������ "������ trivial" ���� �ʽ��ϴ�.

//	void goo() {}    // �Ϲ� ��� �Լ��� ������ trivial�� ������ ���� �ʽ��ϴ�

//	Test() {}	// ����ڰ� ���� ������ - �����Ϸ��� ������ �ϴ� ���� �ִٰ� ����

	Test() = default; // �����Ϸ��� ���� ������, �����Ϸ��� �ϴ� ���� 
						// �ִ��� �������� ��Ȯ�� �˰� �ֽ��ϴ�.
};

int main()
{
	// trivial ���θ� �����ϴ� ���
//	bool b = std::is_trivially_default_constructible_v<Test>; // C++17

	bool b = std::is_trivially_default_constructible<Test>::value; // C++11

	std::cout << b << std::endl;
}