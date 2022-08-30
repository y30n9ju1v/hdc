#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// move 지원 setter 만들기 #1
//	void setName(const std::string& s) { name = s; }			// 1
//	void setName(std::string&& s) { name = std::move(s); }		// 2

	// forwarding reference 를 사용하면 위 2개 함수를 자동생성
	// 할수 있습니다.
	template<typename T>
	void setName(T&& arg)
	{
		// 다음중 맞는 것은 ?
//		name = arg;
//		name = std::move(arg);
		name = sd::forward<T>(arg);
	}
};
int main()
{
	std::string s = "john";
	People p;
	p.setName(s);				// 
	p.setName(std::move(s));	// 

	const std::string cs = "kim";
	p.setName(cs);	// 템플릿이라면 이순간 setName(const std::string& s)생성
	p.setName(s);   // 템플릿이라면 이순간 setName(std::string& s)생성
					// 즉, 생성되는 함수가 많아 집니다.
}

// 위 코드는 "T&&" 사용하지 마세요
// 그냥, setName() 2개 만드세요.

