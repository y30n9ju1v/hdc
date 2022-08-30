#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;

	Point() = default;
	Point(int a, int b) : x(a), y(b) {}
};

// 임의 타입의 배열을 복사하는 copy 를 생각해 봅시다.
template<typename T> 
void copy(T* dst, T* src, std::size_t size)
{
	// 복사 생성자가 trivial(모든 멤버를 얕은 복사)한가에 따라
	// 다른 구현
	if (std::is_trivially_copy_constructible<T>::value)
	{
		std::cout << "memcpy 사용" << std::endl;
		memcpy(dst, src, sizeof(T) * size);
	}
	else
	{
		std::cout << "각 객체를 복사생성자를 호출해서 복사" << std::endl;
		while (size--)
		{
			new(dst) T(*src); // 내일 배웁니다.
			++dst, ++src;
		}
	}
}

int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];

	
	copy(pt2, pt1, 5);

}