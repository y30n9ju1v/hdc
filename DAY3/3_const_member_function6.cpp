#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1,2,3,7,8,9,4,5,6,10 };

	// range for ����
	for (auto n : v)	// v.begin()/v.end() �� ����ؼ� ����.. 
		std::cout << n << ", ";

	std::cout << std::endl;
}