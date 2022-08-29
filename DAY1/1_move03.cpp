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

	// lvalue, rvalue 모두 받을수있다.
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "copy" << std::endl;
	}	
	// 임시객체(rvalue) 전용 복사 생성자를 만들자.
	// rvalue 만 받을수 있다.
	Cat(Cat&& c) 
		: name(c.name), age(c.age) // 1. 포인터 포함 모든 멤버를 얕은복사
	{
		// 이제 임시객체는 더이상 자원을 주소를 가지고 있으면
		// 안됩니다.
		c.name = nullptr;
				// => 이코드가 되려면 
				//    임시객체를 상수성 없이 가리킬수 있어야 합니다.
		std::cout << "move" << std::endl;
	}
};
// 결론 : 이름있는 객체를 복사 할때와
//       임시객체를 복사할때 다른 코드를 만들어서 성능향상을 위한것

// 복사(copy) 생성자 : 이름 있는 객체를복사 할때 (깊은 복사)
// 이동(move) 생성자 : 이름 없는 객체(임시객체)를 복사 할때 (자원의 이동)



Cat fn()
{
	Cat c("yaong", 2);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;

	Cat c3 = fn(); // 핵심. 이때의 메모리 그림과, 동작 방식을 생각해 보세요
}