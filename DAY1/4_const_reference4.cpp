#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// �Ʒ� �ڵ�� C++98 �������� "���� ���� �ڵ�" �Դϴ�.
	// �׷���, C++11 ������ ���������� �ֽ��ϴ�.
	// => �Ʒ� �Լ��� move �� �����Ҽ� �����ϴ�.
	void setName(const std::string& s)
	{
		name = s;	// ������ ���� ���Կ����� ȣ��

//		name = std::move(s); // ���� ������ ���� ���� ������
							// s �� const �̹Ƿ�.. 
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);             // s1�� �ڿ��� ������ ����� ��
	p.setName(std::move(s2) ); // s2�� �ڿ��� �̵��� ����� ��

	std::cout << s1 << std::endl; // "john"
	std::cout << s2 << std::endl; // ""  ������ ���Ѵ�.
}

