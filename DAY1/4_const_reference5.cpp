#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// move�� �����ϴ� setter �����
	// ��� 1. 2���� setter
	void setName(const std::string& s) 	{ name = s;	}
	void setName(std::string&& s)		
	{ 
		// s�� �̸��� �ֽ��ϴ�. ���� lvalue �Դϴ�.
//		name = s;  // move ������ �ƴ϶� ���� ������ ����ϰ� �˴ϴ�.
		name = std::move(s);
	}
};



int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);            
	p.setName(std::move(s2)); 
			// static_cast<std::string&&>(s2)

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl; 

	std::vector<std::string> v;

	v.push_back(s1);
	v.push_back(std::move(s1));
}




// ����
// Point pt;
// Point&& r = Point();

// Ÿ�԰� value �Ӽ��� �򰥸��� ������
//			Ÿ��			value �Ӽ�
// pt		Point		lvalue
// r		Point&&		lvalue
// Point()	Point		rvalue
