#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;

	// 성능향상을 위해 "문자열 캐쉬" 도입
	mutable char cache[32];
	mutable bool cache_valid = false;
		// mutable member data
		// => 상수 멤버 함수에서도 멤버의 값을 수정할수 있게 해달라는 의미

public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// toString()은 객체의 상태는 x, y 를 변경하지 않으므로
	// => 상수 멤버 함수가 되어야 합니다.
	// 
	// 그런데, 테크닉(캐쉬) 때문에 멤버(cache) 가 변경되어야 합니다.
	const char* toString() const
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y); // cache update

			cache_valid = true;
		}
		return cache;
	}
	void set(int a, int b)
	{
		x = a;
		y = b;
		cache_valid = false;
	}
};
int main()
{
	Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}

