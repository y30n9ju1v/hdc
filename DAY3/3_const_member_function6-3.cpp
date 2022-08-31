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

	auto begin() const { return r.cbegin(); }
	auto end()   const { return r.cbegin() + count; }

	auto begin() { return r.begin(); }
	auto end()   { return r.begin() + count; }

	// empty 함수는 const member function 로 할까요 ? 하지 말까요 ?
	// => 반드시 상수 멤버함수 이어야 합니다.
	bool empty() const
	{
		return begin() == end();
	}
};

int main()
{
	std::vector<int> v = { 1,2,3,7,8,9,4,5,6,10 };

	      take_view tv1(v, 3);
	const take_view tv2(v, 3);

	bool b1 = tv1.empty();
	bool b2 = tv2.empty();

	auto p1 = tv1.begin(); // 비상수객체의 begin()
	auto p2 = tv2.begin(); //  상수객체의 begin()
	*p1 = 10;	// 되야 합니다.
//	*p2 = 10;	// 안되야 합니다.
}