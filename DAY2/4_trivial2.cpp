#include <iostream>
#include <type_traits> 

class Test
{
//	int data;
	int data = 0; // 초기값을 넣는 코드는 결국 생성자에서 하는 것입니다.
					// 즉, 이 코드 때문에 생성자는 trivial 하지 않습니다.
public:
//	virtual void foo() {} // 가상함수가 있으면 "생성자 trivial" 하지 않습니다.

//	void goo() {}    // 일반 멤버 함수는 생성자 trivial에 영향을 주지 않습니다

//	Test() {}	// 사용자가 만든 생성자 - 컴파일러는 무조건 하는 일이 있다고 생각

	Test() = default; // 컴파일러가 만든 생성자, 컴파일러는 하는 일이 
						// 있는지 없는지를 정확히 알고 있습니다.
};

int main()
{
	// trivial 여부를 조사하는 방법
//	bool b = std::is_trivially_default_constructible_v<Test>; // C++17

	bool b = std::is_trivially_default_constructible<Test>::value; // C++11

	std::cout << b << std::endl;
}