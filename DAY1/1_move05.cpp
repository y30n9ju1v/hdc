// move05
#include <string>
#include <iostream>

int main()
{
	std::string s1 = "abcdefghijklmnop";
	std::string s2 = s1;// ���� ���� �Դϴ�.

	std::string s3 = "abcdefghijklmnop";
	std::string s4 = std::move(s3);// �ڿ��� �̵� �Դϴ�.
									// static_cast<std::string&&>(s3)
									// std::string �� move ������ ȣ��
									


	// s3�� �ڿ�(���ڿ�)�� �����ϴ�.
	// ������ ��ȿ�� ��ü�Դϴ�.
	std::cout << s1 << std::endl;  // ���ڿ�����
	std::cout << s3 << std::endl;  // ""

}
// move �Ŀ� (c1) ��ü��� �����Ѱǰ���
// => move ������ ������ ���� �ٸ���..
// => guide line ������ �׻� ��ȿ�ϰ� �϶�!! ��� �մϴ�.
