#include <iostream>
#include <string>

// �ڿ��� ���� �������� ����, std::string ���� Ŭ������ ����ϸ�
// "�Ҹ���, ���� ������, ���� ����, move ������, move ����" ��� 
// �����ʿ� ����.
// => ������, �����Ϸ��� ��� �����Ѵ�.
// 
// rule of 0  : ���� ���� �ڵ�.

// ��������� string�� �ƴ϶� int �̸� 
// �����Ϸ��� ���� move �����ڴ� ��� �ǳ���?
// int n = 0;
// int n2 = n; // ���ڵ��
// int n3 = std::move(n); // �� �ڵ�� �Ϻ��� �����մϴ�.
					   // int �� move �����ڰ� ���� Ÿ���̹Ƿ�

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

	People p2 = p1;  // ���� ������

	p2 = p1;		// ���Կ����� ( p2.operator=(p1)) 


	People p3 = std::move(p1);
	p3 = std::move(p2);
}




