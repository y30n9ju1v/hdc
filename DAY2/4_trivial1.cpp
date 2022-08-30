// SL.con.4: don’t use memset or memcpy for arguments that are 
//           not "trivially-copyable"

#include <iostream>

// trivial : 해당 함수가 하는 일이 "자명(널리 알려진 디폴트 방식대로 동작)" 한다는 의미.
// trivial 생성자      : 아무 일도 하지 않은 생성자
// trivial 복사 생성자 : 모든 멤버를 얕은 복사하는 복사 생성자.
// trivial 소멸자     : 아무일도 하지 않는다.

class A
{
};

// B의 생성자는 trivial 할까요 ?
class B //: public A
{
//	A a;
	int data;
public:
//	virtual void foo() {}
};

// 생성자가 trivial 한 조건
// 1. 가상함수가 없고
// 2. 객체형 멤버가 없거나, 객체형 멤버의 생성자가 trivial 하고
// 3. 기반 클래스가 없거나, 기반 클래스의 생성자가 trivial 하고
// 4. 사용자가 만든 생성자가 없을때
// 생성자는 trivial 합니다.
// B b; // 어셈 코드를 보면 "call B::B()" 가 없습니다.





int main()
{
	// 생성자가 trivial 하다는 것은 "하는일이 없다" 는의미.
	// 생성자를 호출하지 않아도 객체를 사용할수 있음을 의미 합니다
	B* p = (B*)malloc(sizeof(B)); // 생성자 호출 안됩니다.

//	p->foo(); // 될까요 ?  안됩니다. 프로그램 비정상 종료


	new(p) B; // 객체 p에 대해 생성자만 호출하는 기술 - 내일 배웁니다.

	p->foo(); // ok.. 생성자를 호출한후 가상함수를 호출하면 문제 없습니다.

}


