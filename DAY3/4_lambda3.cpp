#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{
	// C++은 함수 안에서 함수 만들수 없습니다.
//	int add(int a, int b) { return a + b; }; // error

	// 그런데, 함수 안에서 구조체(함수객체)는 만들수 있습니다.
	struct plus {}; // ok

	// 그래서 람다 표현식도 함수 안에서 됩니다.

	// 람다표현식 
	// 1. 컴파일러가 ()연산자가 재정의된 클래스 생성
	// 2. 생성된 클래스의 임시객체를 만드는 코드
	
	// 람다 표현식을 auto 변수에 담으면 함수 처럼 사용가능 합니다.
	// => main 함수 안에서 새로운 함수를 만든것과 같은 의미(local function)
	auto f = [](int a, int b) { return a + b; };
	      // class xxx{ operator(); }; xxx(); 
	
	int n1 = f(1, 2);

}