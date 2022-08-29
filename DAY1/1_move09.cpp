#include <iostream>
#include <string>

// 자원을 직접 관리하지 말고, std::string 같은 클래스를 사용하면
// "소멸자, 복사 생성자, 복사 대입, move 생성자, move 대입" 모두 
// 만들필요 없다.
// => 하지만, 컴파일러가 모두 제공한다.
// 
// rule of 0  : 가장 좋은 코드.

// 멤버변수가 string이 아니라 int 이면 
// 컴파일러에 의한 move 생성자는 어떻게 되나요?
// int n = 0;
// int n2 = n; // 이코드와
// int n3 = std::move(n); // 이 코드는 완벽히 동일합니다.
					   // int 는 move 생성자가 없는 타입이므로

class People
{
//	char* name;
	std::string name;
	int   age;
public:
	People(const std::string& s, int a) : name(s), age(a)
	{
	}
};


int main()
{
	People p1("kim", 20);

	People p2 = p1;  // 복사 생성자

	p2 = p1;		// 대입연산자 ( p2.operator=(p1)) 


	People p3 = std::move(p1);
	p3 = std::move(p2);
}




