#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// 아래 코드는 C++98 시절에는 "아주 좋은 코드" 입니다.
	// 그런데, C++11 에서는 부족한점이 있습니다.
	// => 아래 함수는 move 를 지원할수 없습니다.
	void setName(const std::string& s)
	{
		name = s;	// 무조건 복사 대입연산자 호출

//		name = std::move(s); // 역시 무조건 복사 대입 연산자
							// s 가 const 이므로.. 
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);             // s1의 자원을 복사해 가라는 것
	p.setName(std::move(s2) ); // s2의 자원을 이동해 가라는 것

	std::cout << s1 << std::endl; // "john"
	std::cout << s2 << std::endl; // ""  나오길 원한다.
}

