#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)

// �Ϲ� �Լ��� Closure �� �ɼ� ������
// �Լ� ��ü�� Closure �� �ɼ� �ֽ��ϴ�.
struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};
int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3;

	IsDivide f(k); // k�� ���� ĸ���� ���� �Լ�(��ü)
	bool b = f(10); // 10 �� k(3)�� ����ΰ� ?

	auto ret1 = std::find_if(v.begin(), v.end(), f);


	// �ѹ��� ����Ѵٸ� �Ʒ�ó�� �ӽð�ü�� �����ϼ���..
	auto ret2 = std::find_if(v.begin(), v.end(), IsDivide(k) );

}
