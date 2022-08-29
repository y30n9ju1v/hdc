// const reference5-1    5번 복사하세요
#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
	std::string address;
public:
	// 아래 코드 생각해 보세요 - move를 지원하려면 어떻게 해야 할까요 ?
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
	// 결론, 인자가 N개인 setter(또는 생성자)가 move를 지원하려면
	// 2^N 개의 setter(생성자)가 필요 합니다.
	// => 다른 방법이 있어야 하지 않을까요 ?
	// => "forwarding reference"을 사용해야 합니다
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


