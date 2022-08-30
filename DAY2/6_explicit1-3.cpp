#include <iostream>

class vector
{
public:
	explicit vector(int sz) { std::cout << "vector(int)" << std::endl; }

	vector(std::initializer_list<int> e) 
	{
		std::cout << "vector(std::initializer_list)" << std::endl; 
	}
};

int main()
{
	vector v1( 10 );
	vector v2{ 10 }; // 1. vector(std::initializer_list)를 먼저 호출, 없으면
					 // 2. vector(int) 사용

//	vector v3 = 10; // error. explicit vector(int) 이므로
	vector v4 = { 10 }; // ok.. std::initializer_list 버전은 explicit 아님

	// 왜 initializer_list 를 인자로 받나요 ?
	// => std::initializer_list 를 인자로 받으면 몇개라도 전달가능합니다.
	vector v5{ 1,2,3,4,5,6,7,8,9,10 };
	vector v6 = { 1,2,3,4,5,6,7,8,9,10 };

	// 아래 2줄의 차이점을 이해하는 것이 아주 중요 합니다.
	std::vector<int> v7(10, 3); // 10개를 3으로
	std::vector<int> v8{10, 3}; // 2개를 10, 3 으로 
}