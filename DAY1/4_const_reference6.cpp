#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	void setName(const std::string& s) { name = s; }
	void setName(std::string&& s)
	{
		name = std::move(s);
	}

	// ���ڷ� ���޵� ���� "retain(����, ��� ����)" �Ҷ���
	// move�� ����ϸ� �˴ϴ�.
	// ���ڷ� ���� ���� "���(�б�)�� �Ѵٸ�" move ������ʿ� �����ϴ�
	// in parameter
	void print_msg(const std::string& s)
	{
		std::cout << "message : " << s << std::endl;
	}
};
int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	// setName : ���ڷ� ���޵� ��ü�� ����(�Ǵ� move)�� �ؼ� ����(retain)�մϴ�.
	p.setName(s1);
	p.setName(std::move(s2));

	// print_msg : ���ڷ� ���޵� ��ü�� �ٸ� ���� �����ϴ� ���� �ƴմϴ�.
	//			   �ڿ��� ������ ���������� move�� ������ʿ� �����ϴ�	
	//			   
	p.print_msg(s1);
	p.print_msg(std::move(s1)); // ��, ����ڰ� �̷��� ����Ҽ�������
								// move ȿ���� �����ϴ�.

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

}

