// F16 ~ F20  ( 10 page ~)
// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const
// F.18 : For "will-move-from" parameters, pass by X&& and std::move the parameter
// F.19 : For "forward" parameters, pass by TP&& and only std::forward the parameter
// F.20 : For "out" output values, prefer return values to output parameters

#include <iostream>
#include <string>

struct Rect
{
	int left, top, right, bottom;
};
// call by value : user type에 사용하는 것은 좋지 않습니다
// 단점 1. 복사본을 생성하므로 메모리 오버헤드
//     2. 복사생성자와 소멸자 호출에 따른 함수 호출의 오버헤드
//     3. 일부 클래스는 복사 생성 자에서 자원 복사에 따른 오버헤드
//void f1(Rect rc) {}
//void f2(std::string s2) {}

// 또한 읽기만 한다면 반드시 const 붙이세요
// 그래야, 임시객체를 받을수 있습니다.
void f1(const Rect& rc)        {}
void f2(const std::string& s2) {}

int main()
{
	Rect rc;
	f1(rc);

	std::string s1 = "to be or not to be";
	f2(s1);
}
