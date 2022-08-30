#include <iostream>

// C50_ Use a factory function if you need “virtual behavior”
// during initialization

// "생성자와 소멸자에서는 가상함수를 호출하지 말라."
// => 가상함수가 동작하지 않습니다.

struct Base
{
	Base() { init(); }  // 무조건 Base init()
						// 만약 이순간 Derived init()이 호출된다면 문제가 있습니다.
						// => Derived::init 이 사용하는 "멤버데이타(x)"는
						//    초기화 되지 않은 상태가 됩니다.


	void foo() { init(); }; // this->init() 인데
							// foo 안에서 this는 Base* 타입입니다
							// => init 이 가상함수가 아니면 "Base init"
							// => init 이 가상함수라면     "Derived init"
							

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1
};

struct Derived : public Base
{
	int x;
	// 사용자 코드			// 컴파일러가 변경한것. x초기화 전에 Base()생성자 호출
	Derived() : x(10) {}	// Derived() : Base(), x(10) {}

	virtual void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
};


int main()
{
	Derived d;
//	d.foo();   // 결과 예측해 보세요
}

