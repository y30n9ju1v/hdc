
// F.53: Avoid capturing by reference in lambdas 
//       that will be used non - locally, 
//       including returned, stored on the heap, or passed to another thread

#include <vector>
#include <functional>

// 람다 표현식에 의해 컴파일러가 자동 생성한 클래스를 다른 문맥에서 또 쓸수있나요?

std::function<int(int, int)> f; // 전역변수 이름로 모든 함수 가 사용가능

void foo()
{
	int num = 10;
	f = [&num](int a, int b) { return a + b + num; };

}	// <== num 파괴. f 가 보관하던 참조는 dangling!

void goo()
{
	int ret = f(1, 2); // 버그.. f는 dangling reference 보관
}



int main()
{
	int num = 10;

	// 핵심 1. value capture, reference capture
//	auto f1 = [num](int a) { num = 20; return num + a; }; // error
				// => 내부적으로 num 의 값. 10 보관
				// => 람다안에서 "num = 20" 등은 에러

	auto f2 = [&num](int a) { num = 20;  return num + a; }; // ok
				// => num 의 참조로 보관

	f2(0);

	std::cout << num << std::endl;

	// 핵심 2. 람다표현식은 auto 뿐 아니라 std::function 에담아도 됩니다.
	auto f3 = [](int a, int b) {return a + b; };

	std::function<int(int, int)> f4 = [](int a, int b) {return a + b; };
}