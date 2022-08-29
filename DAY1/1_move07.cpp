#include <iostream>

// Rule Of 3
// => ������ ����� �ְ�, �����ڿ��� �ڿ� �Ҵ��ϴ� �ڵ尡 �ִٸ�
//    �ݵ�� 3���� Ư�� ��� �Լ��� �� ������ �Ѵ�.
// => �Ҹ���, ���� ������, ���� ������

// Rule Of 5
// => C++11 ���ʹ� move �����ڿ� move ���Ե� ������. 


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
	
	// move ������
	People(People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr;
	}

	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		age = p.age;

		delete[] name;
		
		name = p.name;		// �����͸� ����
		p.name = nullptr;	// ���� ��ü�� �ڿ� ����!

		return *this;
	}
};


int main()
{
	People p1("kim", 20);
	
	People p2 = p1;  // ���� ������

	p2 = p1;		// ���Կ����� ( p2.operator=(p1)) 


	People p3 = std::move(p1);
	p3 = std::move(p2);		  
}




