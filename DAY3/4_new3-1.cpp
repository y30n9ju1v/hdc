// 4_new3-1
#include <iostream>
#include <vector>

class DBConnect
{
public:
	DBConnect() { std::cout << "connect DB" << std::endl; }
	~DBConnect() { std::cout << "close DB" << std::endl; }
};

int main()
{
	std::vector<DBConnect> v(5);

	std::cout << "-------------" << std::endl;
	
	v.resize(3); // �� ������ ������ ������
				// �̼���, ����(�޸�)�� ���ŵ��� �ʽ��ϴ�.
				// ������, �پ�� 2���� ��ü�� ���ؼ��� �Ҹ��ڸ� ȣ���մϴ�.	
				// �޸� ���� ���� �Ҹ��ڸ� ȣ���ϴ� �ڵ尡 �ʿ� �մϴ�.
				// buff[4].~DBConect()  ���� ȣ��.
	
	std::cout << "-------------" << std::endl;

	v.resize(4); // �þ �Ѱ��� ���� �޸� ������ �ֽ��ϴ�.
				 // �׷���, �߰� �޸� �Ҵ��� ������
				 // ���� �޸� ������ ���� "������ ȣ��"�� �ʿ�

	std::cout << "-------------" << std::endl;

}