// const reference5-1    5�� �����ϼ���
#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string address;
public:
	// �Ʒ� �ڵ� ������ ������ - move�� �����Ϸ��� ��� �ؾ� �ұ�� ?
	void set(const std::string& s1, const std::string& s2)
	{
		name = s1;
		address = s2;
	}
	void set(const std::string& s1,std::string&& s2)
	{
		name = s1;
		address = std::move(s2);
	}
	//
	void set(std::string&& s1, const std::string& s2)
	{
		name = std::move(s1);
		address = s2;
	}
	void set(std::string&& s1, std::string&& s2)
	{
		name = std::move(s1);
		address = std::move(s2);
	}
	// ���, ���ڰ� N���� setter(�Ǵ� ������)�� move�� �����Ϸ���
	// 2^N ���� setter(������)�� �ʿ� �մϴ�.
	// => �ٸ� ����� �־�� ���� ������� ?
	// => "forwarding reference"�� ����ؾ� �մϴ�
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul"

	People p;
	p.set(s1, s2);
	p.set(s1, std::move(s2));
	p.set(std::move(s1), s2);

}


