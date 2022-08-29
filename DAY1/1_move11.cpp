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
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}

};
int main()
{
	Object obj1;
	Object obj2 = obj1; // copy

//	Object obj3;
	const Object obj3;

	Object obj4 = std::move(obj3); // move ? copy ? error ?
						// => 상수 객체는 move 될수 없습니다.
						// => 복사 됩니다. 왜?? copy 되나요 ?
						// 
						// static_cast<obj3타입&&>(obj3);
						// static_cast<const Object&&>(obj3);

	// 상수객체는 move 될수 없습니다. std::move 사용시 "복사 생성자" 호출됩니다.
}

