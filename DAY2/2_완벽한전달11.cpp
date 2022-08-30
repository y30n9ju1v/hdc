#include <iostream>

void f0()      { printf("f0\n"); }
void f1(int a) { printf("f1 : %d\n", a); }
int& f3(int a, double d, int& r) { r = 200; return r; }

// 완벽한 전달은
// 1. 가변 인자 템플릿으로 하는 경우가 많습니다.
// 2. 반환 값도 완벽하게 돌려 주려면 "decltype(auto)" 로 반환하면 됩니다.
template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
//	StopWatch sw; // 이 클래스 한개 만드세요
				  // 1. 생성자에서 현재 시간 기록하세요
				  // 2. 소멸자에서 시간 다시 구해서, 생성자에게 기록한시간
				  //    차이를 출력하세요. (함수 수행시간 입니다.)
	return f( std::forward<T>(arg)... );
}

int main()
{
	int n = 0;
	chronometry(f0);
	chronometry(f1, 10);
	int& ret = chronometry(f3, 10, 3.4, n);
	ret = 300; // ret 는 결국 n의 참조
	std::cout << n << std::endl; // 300
}
