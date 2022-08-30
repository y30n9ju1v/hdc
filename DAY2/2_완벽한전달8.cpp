#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// move ���� setter ����� #1
//	void setName(const std::string& s) { name = s; }			// 1
//	void setName(std::string&& s) { name = std::move(s); }		// 2

	// forwarding reference �� ����ϸ� �� 2�� �Լ��� �ڵ�����
	// �Ҽ� �ֽ��ϴ�.
	template<typename T>
	void setName(T&& arg)
	{
		// ������ �´� ���� ?
//		name = arg;
//		name = std::move(arg);
		name = sd::forward<T>(arg);
	}
};
int main()
{
	std::string s = "john";
	People p;
	p.setName(s);				// 
	p.setName(std::move(s));	// 

	const std::string cs = "kim";
	p.setName(cs);	// ���ø��̶�� �̼��� setName(const std::string& s)����
	p.setName(s);   // ���ø��̶�� �̼��� setName(std::string& s)����
					// ��, �����Ǵ� �Լ��� ���� ���ϴ�.
}

// �� �ڵ�� "T&&" ������� ������
// �׳�, setName() 2�� ���弼��.

