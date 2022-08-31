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

	// ������ ����ǥ������ ������ ����Ѵٸ� �Ʒ� ó�� ���� ������
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
				// sort( , , lambda_type1) �� �Լ� �� ����

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
				// sort( , , lambda_type2) �� �Լ� �� ����

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
				// sort( , , lambda_type3) �� �Լ� �� ����

	// ������ ����ǥ������ ������ ����Ѵٸ� auto ������ ���� �Ŀ� ����ϼ���
	auto cmp = [](int a, int b) { return a < b; };
				// class xxx{}; xxx();

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	// => �Ѱ��� sort() �Լ� ����
}