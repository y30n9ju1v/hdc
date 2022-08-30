#include <string>

// 아래 코드들은 move는 지원 안됩니다.

class People1
{
	std::string name;
	int age;
public:
	// 초기화 리스트에서 초기화 : 좋은 코드 입니다.
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
		// 생성자 블럭안에서 "대입" : 좋지 않은 코드 입니다.
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