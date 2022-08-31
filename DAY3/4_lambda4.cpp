// T.141: Use an unnamed lambda 
//        if you need a simple function object in one place only

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	auto f1 = [](int a, int b) {return a + b; };

	std::vector<int> v = { 1,3,5,2,4,6 };

	// 동일한 람다표현식을 여러번 사용한다면 아래 처럼 하지 마세요
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
				// sort( , , lambda_type1) 인 함수 를 생성

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
				// sort( , , lambda_type2) 인 함수 를 생성

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
				// sort( , , lambda_type3) 인 함수 를 생성

	// 동일한 람다표현식을 여러번 사용한다면 auto 변수에 담은 후에 사용하세요
	auto cmp = [](int a, int b) { return a < b; };
				// class xxx{}; xxx();

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	// => 한개의 sort() 함수 생성
}