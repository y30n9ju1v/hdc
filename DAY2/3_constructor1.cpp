#include <string>

// �Ʒ� �ڵ���� move�� ���� �ȵ˴ϴ�.

class People1
{
	std::string name;
	int age;
public:
	// �ʱ�ȭ ����Ʈ���� �ʱ�ȭ : ���� �ڵ� �Դϴ�.
	People1(const std::string& s, int a) : name(s), age(a) 
	{
	}
};

class People2
{
	std::string name;
	int age;
public:
	People2(const std::string& s, int a) 
	{
		// ������ ���ȿ��� "����" : ���� ���� �ڵ� �Դϴ�.
		name = s;
		age = a;
	}
};


int main()
{
	std::string s = "john";

	People1 p1(s, 20);
	People2 p2(s, 20);
}