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
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }

	// 깊은 복사를 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		// 포인터 멤버는 
		// 포인터를 복사하지 말고
		// 메모리 자체를 복사
		name = new char[strlen(c.name) + 1];

		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; 
}