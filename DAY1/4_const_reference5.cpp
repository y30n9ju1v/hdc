#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// move를 지원하는 setter 만들기
	// 방법 1. 2개의 setter
	void setName(const std::string& s) 	{ name = s;	}
	void setName(std::string&& s)		
	{ 
		// s는 이름이 있습니다. 따라서 lvalue 입니다.
//		name = s;  // move 대입이 아니라 복사 대입을 사용하게 됩니다.
		name = std::move(s);
	}
};



int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);            
	p.setName(std::move(s2)); 
			// static_cast<std::string&&>(s2)

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl; 

	std::vector<std::string> v;

	v.push_back(s1);
	v.push_back(std::move(s1));
}




// 참고
// Point pt;
// Point&& r = Point();

// 타입과 value 속성을 헷갈리지 마세요
//			타입			value 속성
// pt		Point		lvalue
// r		Point&&		lvalue
// Point()	Point		rvalue
