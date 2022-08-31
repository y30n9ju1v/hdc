// SL.str.2: Use std::string_view or 
//          gsl::span<char>(c++20) to refer to character sequences

#include <iostream>
#include <string>
#include <string_view>


void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}


// 인자로 전달된 문자열을 "읽기만한다면"
// => 보관하지 않으므로 move 고려할필요 없습니다.

// void f(std::string s) {} // call by value : 좋지 않습니다.


// 2. const reference
void f1(const std::string& s) {}

// 3. 위 코드 보다 아래가 좀더 좋습니다.
void f2(std::string_view sv) {}   // string_view 는 value 로 받으세요


int main()
{
//	std::string s1 = "sfjsdjflsdjflsjlfks";
//	f1(s1);
//	f2(s1);

	// 아래 코드를 잘생각 하세요
//	f1("sdjsdjflsjflskdjflkds"); // 1. 인자로 보내는 문자열 자체는 상수메모리에 있습니다.
								 // 2. 함수가 string& 이므로 string 임시객체 생성
								 //    해서 전달
								 // 3. 임시객체를 만들때 문자열의 복제가 발생
	f2("sdjsdjflsjflskdjflkds");

	// std::string_view : string 에 대한 view 입니다
	// C++20  std::span : 범용적 용도의 view 입니다.
	//						모든 종류의 연속된 메모리에 대한 view
	//						배열, vector, std::array 등.. 
}