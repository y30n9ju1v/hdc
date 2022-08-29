#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}


	Object(const Object&) 
	{
		std::cout << "copy" << std::endl;	
	}
	// ����
	// move �迭 �Լ��� ���鶧��
	// 1. ���ܰ� �߻����� �ʵ��� �����, (��κ� ������ ���� �̹Ƿ� ���� �����ϴ�.)
	// 2. ���ܰ� ���ٴ� ����� �����Ϸ����� �˸�����
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};
int main()
{
	Object obj1;
	Object obj2 = obj1; // ������ ���� ������
	Object obj3 = std::move(obj1); // ������ move ������
	Object obj4 = std::move_if_noexcept(obj1); 
					// move �����ڿ� ���ܰ� ���ٸ� move ���
					// move �����ڿ� ���ܰ��ɼ��� �ִٸ� copy ���

	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // �̼����� ������ �����غ��ô�.

	std::cout << "----------------" << std::endl;
}

