#include <iostream>
#include <string>
// �ٽ� 1. ����ڰ� copy �� move �迭�� ��� ������ ������
// => �����Ϸ��� ��� �����Ѵ�.
// => copy �迭(���� ������, ���� ���Կ�����)������ ��� ����� ����� �ű��
// => move �迭(move ������, move ���Կ�����)������ ��� ����� move�� �ű��.
// �ٽ� 2. ����ڰ� copy �迭�� �����
// => �����Ϸ��� move �迭 �Լ��� �ڵ� ���� ����
// => std::move() ���� "����ڰ� ���� ���� ������ ���

// => �����Ϸ����� ��û�Ϸ��� "=default" ���

// �ٽ� 3. ����ڰ� move �迭�� ���������
// => �����Ϸ��� ���� �迭�� ��� "����" �մϴ�.
// => ���� �迭�� �ʿ��� �ڵ尡 ������ "����"

// => �����Ϸ��� ����� ���� �迭�� �ʿ��ϸ� "=default" ��û�ϸ� �˴ϴ�.

class Object
{
public:
	std::string name;

	Object(const std::string& n) : name(n) {} // "������" �Դϴ�.

	Object(Object&& obj) : name(std::move(obj.name))
	{
		std::cout << "����ڰ� ���� move ������" << std::endl;
	}

	// =default �Ϸ��� 
	// �����ڰ� ���� �� �ܿ� ������ ����/move �迭�� ��� ��û�ϴ� ���� �����Դϴ�.
//	Object(Object&&) = default;
//	Object& operator=(const Object& obj) = default;
//	Object& operator=(Object&& obj) = default;
};

int main()
{
	Object obj1("obj1");
	Object obj2("obj2");
	Object obj3 = obj1;
	Object obj4 = std::move(obj2);
	
	std::cout << obj1.name << std::endl;
	std::cout << obj2.name << std::endl;
}