#include <iostream>

// Rule Of 3/5
class People
{
	char* name;
	int   age;
public:
	People(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s)+1, s);
	}
	~People() { delete[] name; }

	People(const People& p) : age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}

	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		age = p.age;

		delete[] name;

		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		return *this;
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




