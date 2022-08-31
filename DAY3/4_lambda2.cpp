#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)
bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	// 1. 주어진 구간에서 첫번째 나오는 "3"을 찾아라
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// 2. 주어진 구간에서 첫번째 나오는 "3의 배수"를 찾아라
	auto ret2 = std::find_if(v.begin(), v.end(), foo);

	std::cout << *ret2 << std::endl; // 6


	// 3. 주어진 구간에서 첫번째 나오는 "k의 배수"를 찾아라
	int k = 3;
	std::cin >> k;
	auto ret2 = std::find_if(v.begin(), v.end(), ???);

}
// 일급 객체
// => 함수 인자로 전달 가능한 객체
// => C/C++ 언어는 함수도 인자로 전달 가능합니다
// => 그래서, "함수도 일급객체" 라고 표현합니다.

// Closure - 모든 언어에서 사용하는 용어
// => 문맥에 포함된 지역변수를 캡쳐 할수 있는 일급 객체
// => "k + 함수" 를 인자로 보내고 싶다는 의미