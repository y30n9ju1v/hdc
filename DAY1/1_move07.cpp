#include <iostream>

// Rule Of 3
// => 포인터 멤버가 있고, 생성자에서 자원 할당하는 코드가 있다면
//    반드시 3개의 특별 멤버 함수를 더 만들어야 한다.
// => 소멸자, 복사 생성자, 대입 연산자

// Rule Of 5
// => C++11 부터는 move 생성자와 move 대입도 만들어라. 


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
	
	// move 생성자
	People(People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr;
	}

	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		age = p.age;

		delete[] name;
		
		name = p.name;		// 포인터만 복사
		p.name = nullptr;	// 원래 객체가 자원 포기!

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




