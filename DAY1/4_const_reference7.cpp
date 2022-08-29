#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// 생성자도 setter 처럼 move 고려해야 합니다.
	// => 직접 만들면 5-2번예제 처럼 4개의 생성자가 필요 합니다.
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