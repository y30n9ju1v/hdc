#include <iostream>

// C.140: Do not provide different default arguments 
//        for a virtual function and an overrider

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};

class Derived : public Base
{
public:
	// 핵심 : 함수 인자의 디폴트 값을 변경했습니다. 
	// => 절대 이렇게 하면 안됩니다.
	// => 에러는 아니지만.. 
	virtual void foo(int a = 20) { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;
	p->foo(); // Derived : 10
				// 1. 컴파일러는 p 가 Base* 라고 생각합니다.
				// 2. Base 클래스에서 foo 함수의 선언을 조사합니다.
				// 3. foo 에 인자가 없으므로 컴파일러가 컴파일 시간에 디폴트값
				//    으로 인자를 채워 줍니다.
				// "p->foo(10)" 의 코드로 컴파일 시간에 변경
		
				// 4. 그런데, foo 는 가상함수 이므로 실제 어느 함수를 호출할지는
				//	  실행시간에 p가 가리키는 곳을 조사해서 결정
				//    => Derived 를 가리키므로 Derived::foo(10)의 형태로 호출
	Derived d;
	d.foo(); // Derived : 20



	// 디폴트 인자 : 컴파일 시간에 컴파일러가 추가 하는 문법
	// 가상 함수   : 실행시간에 함수 호출을 결정하는 문법

	// 컴파일 시간 문법과 실행시간 문법을 혼용해서 사용하지 마세요
}
