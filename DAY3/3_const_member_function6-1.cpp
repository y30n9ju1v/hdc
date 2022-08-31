#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class take_view 
{
	T& r;
	int count;
public:
	take_view(T& r, int c) : r(r), count(c) {}

	auto begin() { return r.begin(); }
	auto end()   { return r.begin() + count; }
};

template<typename T>
class reverse_view
{
	T& r;
public:
	reverse_view(T& r) : r(r) {}

	auto begin() { return r.rbegin(); }
	auto end()   { return r.rend(); }
};

int main()
{
	std::vector<int> v = { 1,2,3,7,8,9,4,5,6,10 };
	
	take_view tv(v, 3); // C++17 부터는 템플릿 인자 전달안해도 됩니다.
	reverse_view rv(v);

//	for (auto n : v)	// vector 의 모든 요소
//	for (auto n : tv)	// 앞에 3개만 열거
	for (auto n : rv)
		std::cout << n << ", ";


}