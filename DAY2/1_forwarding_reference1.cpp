// F.19: For “forward” parameters, pass by TP&& and only std::forward the parameter

template<typename T> void foo(T a)
{
	T& r = a;	// int& &r = a;
				// int& r = a;
}


int main()
{
	int n = 10;

	int&  r1 = n ; // lvalue reference
	int&& r2 = 10; // rvalue reference 

	// 핵심 1. 포인터의 포인터는 만들수 있지만
	//        reference 의 reference는 만들수 없습니다.
//	int* *p;		// 포인터의 포인터는 만들수 있습니다.
//	int& & r3 = ? ; // reference 의 reference.. error


	// 핵심 2. 타입추론 과정에서 발생하는 reference 충돌은
	//		 오류가 아니라 "reference collapsing" 규칙에 따라 결정된다.

	using LREF = int&; // typedef int& LREF;
	using RREF = int&&;

	LREF r4 = n ;
	RREF r5 = 10;

	// 핵심 3. "reference collapsing" 규칙 외우세요.
	// => 템플릿 만들때 주로 사용합니다.
	LREF& r6 = n ;  // int&  &		=> int&
	RREF& r7 = n ;  // int&& &		=> int&
	LREF&& r8 = n ; // int&  &&		=> int&
	RREF&& r9 = 10;	// int&& &&		=> int&&

	// ex) 
	foo<int&>(n);
}





