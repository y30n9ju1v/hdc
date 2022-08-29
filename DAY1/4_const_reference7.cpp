#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// �����ڵ� setter ó�� move ����ؾ� �մϴ�.
	// => ���� ����� 5-2������ ó�� 4���� �����ڰ� �ʿ� �մϴ�.
	People(const std::string& name, const std::string& addr) 
		: name(name), addr(addr)
	{
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2);
	People p2(s1, std::move(s2));
}