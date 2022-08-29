// move05
#include <string>
#include <iostream>

int main()
{
	std::string s1 = "abcdefghijklmnop";
	std::string s2 = s1;// 깊은 복사 입니다.

	std::string s3 = "abcdefghijklmnop";
	std::string s4 = std::move(s3);// 자원의 이동 입니다.
									// static_cast<std::string&&>(s3)
									// std::string 의 move 생성자 호출
									


	// s3는 자원(문자열)이 없습니다.
	// 하지만 유효한 객체입니다.
	std::cout << s1 << std::endl;  // 문자열있음
	std::cout << s3 << std::endl;  // ""

}
// move 후에 (c1) 객체사용 가능한건가요
// => move 생성자 구현에 따라 다른데..
// => guide line 에서는 항상 유효하게 하라!! 라고 합니다.
