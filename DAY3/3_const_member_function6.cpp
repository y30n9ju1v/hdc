#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1,2,3,7,8,9,4,5,6,10 };

	// range for 원리
	for (auto n : v)	// v.begin()/v.end() 를 사용해서 구현.. 
		std::cout << n << ", ";

	std::cout << std::endl;
}