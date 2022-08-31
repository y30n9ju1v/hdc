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
	auto end() { return r.begin() + count; }

	bool empty() 
	{
//		return r.empty(); // 이렇게 하면 안됩니다. 
						  // r 이 비어있지 않아도 count 0 이면 empty입니다.
		return begin() == end();
	}
};



template<typename T>
class reverse_view
{
	T& r;
public:
	reverse_view(T& r) : r(r) {}

	auto begin() { return r.rbegin(); }
	auto end() { return r.rend(); }
};

int main()
{
	std::vector<int> v = { 1,2,3,7,8,9,4,5,6,10 };

	take_view tv(v, 3); 

	bool b = tv.empty(); // 만들어 봅시다.
}