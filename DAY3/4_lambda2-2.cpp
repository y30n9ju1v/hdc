#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3;

	// C++11 부터는 "람다표현식"을 사용하면 "지역변수를 캡쳐" 할수 있습니다.
//	auto ret1 = std::find_if(v.begin(), v.end(), 
//							[k](int n) { return n % k == 0; });
	//-------------------------------------------------------------
	// 사용자가 람다 표현식을 사용하면 컴파일러는 아래 코드를 생성합니다.
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
