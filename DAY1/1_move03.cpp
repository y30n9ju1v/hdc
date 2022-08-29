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

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
};

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