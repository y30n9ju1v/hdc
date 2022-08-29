#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}


	Object(const Object&) 
	{
		std::cout << "copy" << std::endl;	
	}
	// 권장
	// move 계열 함수를 만들때는
	// 1. 예외가 발생하지 않도록 만들고, (대부분 포인터 복사 이므로 예외 없습니다.)
	// 2. 예외가 없다는 사실을 컴파일러에게 알리세요
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};
int main()
{
	Object obj1;
	Object obj2 = obj1; // 무조건 복사 생성자
	Object obj3 = std::move(obj1); // 무조건 move 생성자
	Object obj4 = std::move_if_noexcept(obj1); 
					// move 생성자에 예외가 없다면 move 사용
					// move 생성자에 예외가능성이 있다면 copy 사용

	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

