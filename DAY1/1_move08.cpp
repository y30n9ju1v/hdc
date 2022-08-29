#include <iostream>
#include <string>
// 핵심 1. 사용자가 copy 와 move 계열을 모두 만들지 않으면
// => 컴파일러가 모두 제공한다.
// => copy 계열(복사 생성자, 복사 대입연산자)에서는 모든 멤버를 복사로 옮기고
// => move 계열(move 생성자, move 대입연산자)에서는 모든 멤버를 move로 옮긴다.
// 핵심 2. 사용자가 copy 계열을 만들면
// => 컴파일러는 move 계열 함수를 자동 생성 안함
// => std::move() 사용시 "사용자가 만든 복사 생성자 사용

// => 컴파일러에게 요청하려면 "=default" 사용

// 핵심 3. 사용자가 move 계열만 만들었을때
// => 컴파일러는 복사 계열을 모두 "삭제" 합니다.
// => 복사 계열이 필요한 코드가 있으면 "에러"

// => 컴파일러가 만드는 복사 계열이 필요하면 "=default" 요청하면 됩니다.

class Object
{
public:
	std::string name;

	Object(const std::string& n) : name(n) {} // "생성자" 입니다.

	Object(Object&& obj) : name(std::move(obj.name))
	{
		std::cout << "사용자가 만든 move 생성자" << std::endl;
	}

	// =default 하려면 
	// 개발자가 만든 것 외에 나머지 복사/move 계열을 모두 요청하는 것이 관례입니다.
//	Object(Object&&) = default;
//	Object& operator=(const Object& obj) = default;
//	Object& operator=(Object&& obj) = default;
};

int main()
{
	Object obj1("obj1");
	Object obj2("obj2");
	Object obj3 = obj1;
	Object obj4 = std::move(obj2);
	
	std::cout << obj1.name << std::endl;
	std::cout << obj2.name << std::endl;
}