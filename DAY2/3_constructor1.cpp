#include <string>

// 아래 코드들은 move는 지원 안됩니다.

// C.49: Prefer initialization to assignment in constructors

class People1
{
	std::string name;
	int age;
public:
	// 초기화 리스트에서 초기화 : 좋은 코드 입니다.
	People1(const std::string& s, int a) 
		: name(s), age(a)	// 사용자가 name(string) 의 인자 한개 생성자 호출
	{						// 코드 제공. 
							// 
	}
};
// People1 p("kim", 20); // name 의 생성자 1회 호출로 초기화 완료.

class People2
{
	std::string name;
	int age;
public:
	//										// 컴파일러가 추가한 코드
	People2(const std::string& s, int a)	// : name() <= 1. name의 디폴트
	{										//				  생성자 호출
		
		// 생성자 블럭안에서 "대입" : 좋지 않은 코드 입니다.
		
		name = s;	// 2. name.operator=(s) 즉, 대입연산자 호출
		age = a;
	}
};
// People2 p("kim", 20); // name멤버가 함수 호출 2번이 발생해서 초기화




int main()
{
	std::string s = "john";

	People1 p1(s, 20);
	People2 p2(s, 20);
}