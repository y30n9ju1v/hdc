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
						// => ��� ��ü�� move �ɼ� �����ϴ�.
						// => ���� �˴ϴ�. ��?? copy �ǳ��� ?
						// 
						// static_cast<obj3Ÿ��&&>(obj3);
						// static_cast<const Object&&>(obj3);

	// �����ü�� move �ɼ� �����ϴ�. std::move ���� "���� ������" ȣ��˴ϴ�.
}

