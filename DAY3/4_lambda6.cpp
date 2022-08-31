#include <iostream>

// C170. ����ǥ������ �����ε��� �ʿ� �ϸ� generic ���ٸ� ����ض�. - C++14

int main()
{
	auto add1 = [](int a, int b) { return a + b; };

	std::cout << add1(1,   2) << std::endl;		// 3
	std::cout << add1(1.1, 2.2) << std::endl;	// 3
	std::cout << add1(1,   2.2) << std::endl;	// 3
	std::cout << add1(1.1, 2) << std::endl;		// 3

	//===============================================
	// C++14 ���� �����Ǵ� generic lambda
	auto add2 = [](auto a, auto b) { return a + b; };

	std::cout << add2(1, 2) << std::endl;		// 3
	std::cout << add2(1.1, 2.2) << std::endl;	// 3.3
	std::cout << add2(1, 2.2) << std::endl;		// 3.2
	std::cout << add2(1.1, 2) << std::endl;		// 3.1

	// ���� : () ������ �Լ��� ���ø�. "
	// => �ٽ� : 2���� ���ڰ� ���� �ٸ� ���ø� Ÿ��
	/*
	class CompilerGeneratedName
	{
	public:
		template<typename T1, typename T2>
		auto operator()(T1 a, T2 b)
		{
			return a + b;
		}
	};
	*/
	//==============================================
	// �Ʒ� �ڵ�� 2���� ���ڰ� �޶� �˴ϴ�.
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a);
											a = std::move(b);
											b = std::move(tmp); };

	int n = 10;
	double d = 3.4;
	swap(n, d); // �Ǵ°� �������� ? ������ �������� ?

	// �� ������ �ذ��ϱ� ����, C++20 ���� 
	// "template lambda" ��� ������ ���ԵǾ����ϴ�.
	auto swap2 = []<typename T>(T & a, T & b) {};
}


