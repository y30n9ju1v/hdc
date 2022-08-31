#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v(10);

	v.resize(7); // ���� ������ ������ ���ô�.

	std::cout << v.size() << std::endl; // 7
	std::cout << v.capacity() << std::endl; // 10 

	v.resize(8);	// ����� capacity > 8 �̹Ƿ� 
					// �޸� ���Ҵ� �ʿ� �����ϴ�.

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10 

	v.shrink_to_fit(); // size==capacity�� �ش޶�� ��

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10 

}
