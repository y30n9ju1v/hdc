#include <iostream>
#include <vector>
#include <string>

void f1(const std::vector<int>& v) {}
void f2(const std::string& s) {}

int main()
{
	std::vector<int> v1(10);  // vector(int) �ֽ��ϴ�.

	std::string s1("aa");		// string(const char*) �ֽ��ϴ�.
}