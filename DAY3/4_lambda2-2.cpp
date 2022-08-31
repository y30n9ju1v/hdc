#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3;

	// C++11 ���ʹ� "����ǥ����"�� ����ϸ� "���������� ĸ��" �Ҽ� �ֽ��ϴ�.
//	auto ret1 = std::find_if(v.begin(), v.end(), 
//							[k](int n) { return n % k == 0; });
	//-------------------------------------------------------------
	// ����ڰ� ���� ǥ������ ����ϸ� �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.
	class CompilerGeneratedName
	{
		int k;
	public:
		CompilerGeneratedName(int n) : k(n) {}

		bool operator()(int n) const
		{
			return n % k == 0;
		}
	};
	auto ret1 = std::find_if(v.begin(), v.end(), 
		CompilerGeneratedName(k));
}
