// const reference5-1    5�� �����ϼ���
#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// move�� �����ϴ� setter �����
	// ��� 1. 2���� setter
	/*
	void setName(const std::string& s) { name = s; }
	void setName(std::string&& s)
	{
		name = std::move(s);
	}
	*/

	// ��� 2. call by value 
	// => C++98 �������� ���ڴٰ� ������� C++11 ���ʹ� ���� ���۰��� �ƴմϴ�.
	void setName(std::string s)
	{
//		name = s; // C++98 ���� "���纻�� �ٽ� �����ϹǷ� �����ϴ�."
		name = std::move(s);//C++11 "���纻�� move �ϹǷ� ��� ���� �����ϴ�."

		// ���, ��� 1 ó�� 2���� ����� ���� �ּ��� �ڵ�����
		// ��� 2 ó�� call by value �� ���� ���۰��� �ƴմϴ�.
		// ���� ���¼ҽ����� ���� call by value �� ���� �ֽ��ϴ�.
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	//								��� 1			��� 2
	p.setName(s1);				//  �������1ȸ		�������1ȸ, �̵�����1ȸ
	p.setName(std::move(s2));	//	�̵�����1ȸ		�̵�����1ȸ, �̵�����1ȸ

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

}


