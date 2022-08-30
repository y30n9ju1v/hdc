#include <iostream>

// ������ ȣ����� �� �˾� �μ���.

struct BM	// Base Member ��� �ǹ̷� "BM" �̶�� �߽��ϴ�
{
	BM() { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};

struct DM	// Derived Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;

	// ����ڰ� ���� �ڵ�		// �����Ϸ��� �����Ѱ�
	Base()					// Base() : bm() <= �������Ÿ ����Ʈ������
	{						//					ȣ�� �ڵ� �߰�
		std::cout << "Base()" << std::endl;
	}
	~Base() 
	{ 
		std::cout << "~Base()" << std::endl; 

		// ~bm();
	}
};
struct Derived : public Base
{
	DM dm;
	// �ٽ� 1. Derived �����ڿ���, ���Ŭ����, ��� ����Ÿ ������ ȣ���ϴ� �ڵ带
	//        �����Ϸ��� �߰��� �ִ� ��
	
	// �ٽ� 2. ������ ȣ�� ������ �����ڰ� �����Ҽ� �����ϴ�

	// ����� �ڵ�		// �����Ϸ��� ������ ��
//	Derived()			// Derived() : Base(), dm()

	Derived() : dm(), Base() // <= ��� ����Ÿ �����ڸ� ����ȣ���ϴ°�ó��
							 //     ��������, ��� Ŭ���� �����ڰ� ���� ȣ��
	{
		std::cout << "Derived()" << std::endl;
	}
	~Derived() 
	{
		std::cout << "~Derived()" << std::endl; 
		// ~dm();
		// ~Base();
	}
};
int main()
{
	Derived d;	// �� ������ ����� ������ ������.
				// call Derived::Derived() �Դϴ�.
}
