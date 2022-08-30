#include <iostream>
#include <vector>
#include <string>

void f1(const std::vector<int>& v) {}
void f2(const std::string& s) {}

int main()
{
	std::vector<int> v1(10);  // explicit vector(int) �ֽ��ϴ�.

	f1(10); // �������� �ȵǴ� ���� �����ϴ�.
			// �׷��� ���� �Դϴ�.
			// ��, vector �� ���� �ʱ�ȭ �ȵ˴ϴ�.

	std::vector<int> v2 = 10;	// error
								// �����ڰ� explicit ��� �ǹ�


	std::string s1("aa");	  // string(const char*) �ֽ��ϴ�.
	f2("aa");	// �������� ���� �����ϴ�. �Ǵ� ���� �����ϴ�.
				// ���� �ƴմϴ�.
				// string �� ���� �ʱ�ȭ�� �˴ϴ�.
	std::string s2 = "aa";	// ok.. 
							// �����ڰ� explicit �� �ƴ϶�� �ǹ�.

	// �����ڸ� explicit �� ���� �����ϴ� ���� ��ó�� �Լ� ���ڷ� 
	// �����ϴ� ��츦 ����� ���� ���� �ϼ���.

	// ���� ������ ����..
	std::vector<int> v3 = 10; // error
	std::vector<int> v4 = { 10 }; // ok.. �� �ǳ��� ??
}
