#include <iostream>
#include <string>
#include <string_view>

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

int main()
{
	// std::string �� ���ڿ��� �׻� ���� ���������� �ʽ��ϴ�.
	// �F�� ���ڿ� : ��ü�ȿ� �׳� ����
	// ��   ���ڿ� : ���� �޸� �Ҵ��� ����
	// ���� : �����Ϸ� ���� �ٸ��� �ֽ��ϴ�. ���� 16�� ����
	// SSO ( Small String Optimization ) �̶�� �մϴ�.
	

//	std::string s1 = "abcd";

	std::string s2 = "aas;dalsjdasjdadjslbcd";

}