#include <iostream>
#include <vector>

class Object
{
public:
	Object(int n, int* p) {}
};

int main()
{
	std::vector<Object> v;

	// 1. 객체를 생성한 후 넣기
	Object obj(0, 0);  //  ok
	v.push_back(obj);

	// 2. 객체를 생성하기 위한 생성자 인자를 전달하기 - emplace!!!
//	v.emplace_back(0, 0); // error
	v.emplace_back(0, nullptr); // ok..

	// 위 처럼 0을 직접 포인터변수에 보내는 것이 아니라
	// 다른곳에 을 거쳐서 전달(완벽한 전달) 할때는 0을 보낼수 없습니다
	// 그래서, nullptr을 만든것 입니다.
}




