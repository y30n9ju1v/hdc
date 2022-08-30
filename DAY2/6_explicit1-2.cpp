#include <iostream>
#include <vector>
#include <string>

void f1(const std::vector<int>& v) {}
void f2(const std::string& s) {}

int main()
{
	std::vector<int> v1(10);  // explicit vector(int) 있습니다.

	f1(10); // 논리적으로 안되는 것이 좋습니다.
			// 그래서 에러 입니다.
			// 즉, vector 는 복사 초기화 안됩니다.

	std::vector<int> v2 = 10;	// error
								// 생성자가 explicit 라는 의미


	std::string s1("aa");	  // string(const char*) 있습니다.
	f2("aa");	// 논리적으로 문제 없습니다. 되는 것이 좋습니다.
				// 에러 아닙니다.
				// string 은 복사 초기화가 됩니다.
	std::string s2 = "aa";	// ok.. 
							// 생성자가 explicit 가 아니라는 의미.

	// 생성자를 explicit 로 할지 결정하는 것은 위처럼 함수 인자로 
	// 전달하는 경우를 만들어 놓고 생각 하세요.

	// 자주 나오는 질문..
	std::vector<int> v3 = 10; // error
	std::vector<int> v4 = { 10 }; // ok.. 왜 되나요 ??
}
