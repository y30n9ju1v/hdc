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
//		return r.empty(); // �̷��� �ϸ� �ȵ˴ϴ�. 
						  // r �� ������� �ʾƵ� count 0 �̸� empty�Դϴ�.
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

	bool b = tv.empty(); // ����� ���ô�.
}