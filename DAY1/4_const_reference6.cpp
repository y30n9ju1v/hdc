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

	// 인자로 전달된 값을 "retain(유지, 어딘가 보관)" 할때만
	// move를 고려하면 됩니다.
	// 인자로 받은 것을 "사용(읽기)만 한다면" move 고려할필요 없습니다
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
	// setName : 인자로 전달된 객체를 복사(또는 move)로 해서 보관(retain)합니다.
	p.setName(s1);
	p.setName(std::move(s2));

	// print_msg : 인자로 전달된 객체를 다른 곳에 보관하는 것은 아닙니다.
	//			   자원을 별도로 보관하지는 move를 고려할필요 없습니다	
	//			   
	p.print_msg(s1);
	p.print_msg(std::move(s1)); // 단, 사용자가 이렇게 사용할수있지만
								// move 효과는 없습니다.

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

}

