#include <string>

// �Ʒ� �ڵ���� move�� ���� �ȵ˴ϴ�.

// C.49: Prefer initialization to assignment in constructors

class People1
{
	std::string name;
	int age;
public:
	// �ʱ�ȭ ����Ʈ���� �ʱ�ȭ : ���� �ڵ� �Դϴ�.
	People1(const std::string& s, int a) 
		: name(s), age(a)	// ����ڰ� name(string) �� ���� �Ѱ� ������ ȣ��
	{						// �ڵ� ����. 
							// 
	}
};
// People1 p("kim", 20); // name �� ������ 1ȸ ȣ��� �ʱ�ȭ �Ϸ�.

class People2
{
	std::string name;
	int age;
public:
	//										// �����Ϸ��� �߰��� �ڵ�
	People2(const std::string& s, int a)	// : name() <= 1. name�� ����Ʈ
	{										//				  ������ ȣ��
		
		// ������ ���ȿ��� "����" : ���� ���� �ڵ� �Դϴ�.
		
		name = s;	// 2. name.operator=(s) ��, ���Կ����� ȣ��
		age = a;
	}
};
// People2 p("kim", 20); // name����� �Լ� ȣ�� 2���� �߻��ؼ� �ʱ�ȭ




int main()
{
	std::string s = "john";

	People1 p1(s, 20);
	People2 p2(s, 20);
}