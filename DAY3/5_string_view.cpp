// SL.str.2: Use std::string_view or 
//          gsl::span<char>(c++20) to refer to character sequences

#include <iostream>
#include <string>
#include <string_view>

// 인자로 전달된 문자열을 "읽기만한다면"
void f(std::string s)
{
	
}

int main()
{
	std::string s1 = "sfjsdjflsdjflsjlfks";
	std::string s2 = s1;	// s1이 가진 문자열 자체를 복사
							// s1, s2 는 각자 자신의 문자열을 소유.

	std::string_view sv = s1; // C++17
						// sv 는 s1의 문자열을 가리킵니다.
						// sv 는 자원(문자열)을 소유하지 않습니다.
						// C++20 에서 "borrowed range" 라는 개념으로 발전
	sv[0] = 'a';	// error
					// string_view로는 읽기만 가능
	
}