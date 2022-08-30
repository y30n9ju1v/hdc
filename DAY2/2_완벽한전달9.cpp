#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// 아래 처럼 하면 move 지원이 안됩니다.
	// 인자가 2개 이므로 move 지원하려면 2^2 => 4개의 함수 필요
	/*
	void set(const std::string& s1, const std::string& s2)
	{
		name = s1;
		addr = s2;
	}
	*/

	// 인자가 2개 이상 있을때 move 지원하려면 
	// "forwarding reference"로 만드세요
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		addr = std::forward<T2>(a);
	}

	// 생성자도 생각해 보세요
	// => 아래 모양은 move 지원 안됩니다.
//	People(const std::string& n, const std::string& a)
//		: name(n), addr(a) {}

	
	// 아래 코드가 move를 지원하는 생성자 입니다
	// lvalue 를 받으면 copy, rvalue 를 받으면 move
	template<typename T1, typename T2>
	People(T1&& n, T2&& a) 
		: name(std::forward<T1>(n)), addr(std::forward<T2>(a))
	{
	}
};


int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2); 
	People p2(std::move(s1), s2); 
	People p3(s1, std::move(s2)); 
								  
	People p4(std::move(s1), std::move(s2));

}