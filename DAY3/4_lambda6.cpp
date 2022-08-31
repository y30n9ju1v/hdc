#include <iostream>

// C170. 람다표현식이 오버로딩이 필요 하면 generic 람다를 사용해라. - C++14

int main()
{
	auto add1 = [](int a, int b) { return a + b; };

	std::cout << add1(1,   2) << std::endl;		// 3
	std::cout << add1(1.1, 2.2) << std::endl;	// 3
	std::cout << add1(1,   2.2) << std::endl;	// 3
	std::cout << add1(1.1, 2) << std::endl;		// 3

	//===============================================
	// C++14 부터 지원되는 generic lambda
	auto add2 = [](auto a, auto b) { return a + b; };

	std::cout << add2(1, 2) << std::endl;		// 3
	std::cout << add2(1.1, 2.2) << std::endl;	// 3.3
	std::cout << add2(1, 2.2) << std::endl;		// 3.2
	std::cout << add2(1.1, 2) << std::endl;		// 3.1

	// 원리 : () 연산자 함수가 템플릿. "
	// => 핵심 : 2개의 인자가 서로 다른 템플릿 타입
	/*
	class CompilerGeneratedName
	{
	public:
		template<typename T1, typename T2>
		auto operator()(T1 a, T2 b)
		{
			return a + b;
		}
	};
	*/
	//==============================================
	// 아래 코드는 2개의 인자가 달라도 됩니다.
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a);
											a = std::move(b);
											b = std::move(tmp); };

	int n = 10;
	double d = 3.4;
	swap(n, d); // 되는게 좋으세요 ? 에러가 좋으세요 ?

	// 위 문제를 해결하기 위해, C++20 에서 
	// "template lambda" 라는 개념이 도입되었습니다.
	auto swap2 = []<typename T>(T & a, T & b) {};
}


