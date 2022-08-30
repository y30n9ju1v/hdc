#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// �Ʒ� ó�� �ϸ� move ������ �ȵ˴ϴ�.
	// ���ڰ� 2�� �̹Ƿ� move �����Ϸ��� 2^2 => 4���� �Լ� �ʿ�
	/*
	void set(const std::string& s1, const std::string& s2)
	{
		name = s1;
		addr = s2;
	}
	*/

	// ���ڰ� 2�� �̻� ������ move �����Ϸ��� 
	// "forwarding reference"�� ���弼��
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		addr = std::forward<T2>(a);
	}

	// �����ڵ� ������ ������
	// => �Ʒ� ����� move ���� �ȵ˴ϴ�.
//	People(const std::string& n, const std::string& a)
//		: name(n), addr(a) {}

	
	// �Ʒ� �ڵ尡 move�� �����ϴ� ������ �Դϴ�
	// lvalue �� ������ copy, rvalue �� ������ move
	template<typename T1, typename T2>
	People(T1&& n, T2&& a) 
		: name(std::forward<T1>(n)), addr(std::forward<T2>(a))
	{
	}
};


int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2); 
	People p2(std::move(s1), s2); 
	People p3(s1, std::move(s2)); 
								  
	People p4(std::move(s1), std::move(s2));

}