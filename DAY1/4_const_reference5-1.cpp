// const reference5-1    5번 복사하세요
#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// move를 지원하는 setter 만들기
	// 방법 1. 2개의 setter
	/*
	void setName(const std::string& s) { name = s; }
	void setName(std::string&& s)
	{
		name = std::move(s);
	}
	*/

	// 방법 2. call by value 
	// => C++98 시절에는 나쁘다고 배우지만 C++11 부터는 아주 나쁜것은 아닙니다.
	void setName(std::string s)
	{
//		name = s; // C++98 시절 "복사본을 다시 복사하므로 느립니다."
		name = std::move(s);//C++11 "복사본을 move 하므로 어느 정도 빠릅니다."

		// 결론, 방법 1 처럼 2개를 만드는 것이 최선의 코드지만
		// 방법 2 처럼 call by value 도 아주 나쁜것은 아닙니다.
		// 요즘 오픈소스에서 종종 call by value 를 볼수 있습니다.
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	//								방법 1			방법 2
	p.setName(s1);				//  복사대입1회		복사생성1회, 이동대입1회
	p.setName(std::move(s2));	//	이동대입1회		이동생성1회, 이동대입1회

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

}


