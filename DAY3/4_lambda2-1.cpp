#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)

// 일반 함수는 Closure 가 될수 없지만
// 함수 객체를 Closure 가 될수 있습니다.
struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};
int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3;

	IsDivide f(k); // k의 값을 캡쳐한 단항 함수(객체)
	bool b = f(10); // 10 이 k(3)의 배수인가 ?

	auto ret1 = std::find_if(v.begin(), v.end(), f);


	// 한번만 사용한다면 아래처럼 임시객체로 전달하세요..
	auto ret2 = std::find_if(v.begin(), v.end(), IsDivide(k) );

}
