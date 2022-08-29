#include <cstring>
#include <iostream>
// 172 page
class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	// 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "copy" << std::endl;
	}
	/*
	// move 생성자
	Cat(Cat&& c) : name(c.name), age(c.age) 
	{
		c.name = nullptr;
		std::cout << "move" << std::endl;
	}
	*/
};


Cat fn()
{
	Cat c("yaong", 2);
	return c;
}
int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// c1은 lvalue, 복사 생성자 호출
	Cat c3 = fn();	// temporary 반환, move 생성자 호출
	Cat c4 = static_cast<Cat&&>(c1); // c1의 자원을 복사하지말고
									 // 이동해 가라는 것
									// c1 이 즉시 파괴되는것은 아니지만
									// 자원을 c4에 넘겨 준것

	Cat c5 = std::move(c3); // std::move 가 결국
							// 위와 같은 캐스팅을 수행합니다.
}
// 결론 
// 1. 클래스를 만드는 사람은 move 를 지원하기 위해 
//    "복사 생성자" 뿐 아니라 "move 생성자"도 만들어야 합니다.

// 2. 클래스 사용자는 객체를 복사가 아닌 (자원)이동 하려면
//    std::move 를 사용하면 됩니다.

// move 생성자가 없는 타입의 객체 인데, std::move() 를 사용했다면 ??
// => 복사 생성자를 사용합니다.


// std::move
// => 객체를 rvalue(&&) 타입으로 캐스팅하는 역활만 합니다.
// => 캐스팅의 결과로 해당 클래스의 move 생성자가 호출됩니다.

// 여기서 자원이라고 하면, "new"로 동적할당한 변수만 말하는 건가요?
// => 네 맞습니다.!!!
