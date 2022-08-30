#include <iostream>

// 생성자 호출순서 를 알아 두세요.

struct BM	// Base Member 라는 의미로 "BM" 이라고 했습니다
{
	BM() { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};

struct DM	// Derived Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;

	// 사용자가 만든 코드		// 컴파일러가 변경한것
	Base()					// Base() : bm() <= 멤버데이타 디폴트생성자
	{						//					호출 코드 추가
		std::cout << "Base()" << std::endl;
	}
	~Base() 
	{ 
		std::cout << "~Base()" << std::endl; 

		// ~bm();
	}
};
struct Derived : public Base
{
	DM dm;
	// 핵심 1. Derived 생성자에서, 기반클래스, 멤버 데이타 생성자 호출하는 코드를
	//        컴파일러가 추가해 주는 것
	
	// 핵심 2. 생성자 호출 순서는 개발자가 변경할수 없습니다

	// 사용자 코드		// 컴파일러가 변경한 것
//	Derived()			// Derived() : Base(), dm()

	Derived() : dm(), Base() // <= 멤버 데이타 생성자를 먼저호출하는것처럼
							 //     보이지만, 기반 클래스 생성자가 먼저 호출
	{
		std::cout << "Derived()" << std::endl;
	}
	~Derived() 
	{
		std::cout << "~Derived()" << std::endl; 
		// ~dm();
		// ~Base();
	}
};
int main()
{
	Derived d;	// 이 순간의 결과를 예측해 보세요.
				// call Derived::Derived() 입니다.
}
