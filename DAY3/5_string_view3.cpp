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
	// std::string 은 문자열을 항상 힙에 보관하지는 않습니다.
	// 짦은 문자열 : 객체안에 그냥 보관
	// 긴   문자열 : 힙에 메모리 할당후 보관
	// 기준 : 컴파일러 마다 다를수 있습니다. 보통 16자 기준
	// SSO ( Small String Optimization ) 이라고 합니다.
	

//	std::string s1 = "abcd";

	std::string s2 = "aas;dalsjdasjdadjslbcd";

}