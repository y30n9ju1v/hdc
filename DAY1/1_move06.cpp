// move11=> move06 으로 변경해 주세요.
#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 174page
// 아래 코드는 "복사"를 사용한 swap 입니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a; // 자원 깊은 복사
	a = b;
	b = tmp;
}

// 아래 코드가 이동에의한 swap 입니다. 빠릅니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a); // 
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// 알고리즘 작성시 "복사" 대신 "move" 를 잘 활용하면
// 아주 빠른 알고리즘을 만들수있습니다.


