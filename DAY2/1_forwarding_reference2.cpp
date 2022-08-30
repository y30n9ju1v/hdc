// forwarding_reference1 - 아주 아주 중요!!

void f1(int&  r) {}
void f2(int&& r) {}

// 함수인자로
// int&  : int 타입의 lvalue 만 받을수 있다.    "f1(10)" 는 에러
// int&& : int 타입의 rvalue 만 받을수 있다.    "f1( n)" 는 에러

// T& : 임의 타입의 lvalue 만 받을수 있다.

// T&& : 임의 타입의 lvalue, rvalue 를 모두 받을수 있다.
//       => 받을수 있다는 것은, 하나의 함수가 모두 받는 것이 아니라
//       => 해당 함수를 생성한다는 것.
//		 => 생성된 함수는 모두 "call by reference" 이다. 복사본 생성안됨
// 
// 아래 규칙 외우세요
// lvalue 전달 : f4(n) => T=int&, T&&=int&& &  생성된 함수 :f4(int&)
// rvalue 전달 : f4(3) => T=int,  T&&=int&&    생성된 함수 :f4(int&&)

// "universal reference" 라고 부르자고 "effective-modern c++저자" 가 제안
// "forwarding reference" 라고 부르기로 C++ 표준에서는 결정





template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// 1. 사용자가 타입을 직접 전달하는 경우
	f3<int>(n);		// T=int	T&=int&				생성된 함수 : f3(int& a)
	f3<int&>(n);	// T=int&	T&=int& &  =>int&	생성된 함수 : f3(int& a)
	f3<int&&>(n);	// T=int&&	T&=int&& & =>int&	생성된 함수 : f3(int& a)

	// 2. 사용자가 타입을 전달하지 않으면
	//    => 컴파일러가 함수 인자를 보고 함수를 생성할수 있도록 타입을 결정합니다.
	f3(3);	// T를 int, int&, int&& 의 어떤 것으로 결정해도 3을 받을수 없다.
			// 따라서, 컴파일 에러.
	f3(n);	// T=int 로 결정.. 인자는 T& 이므로 f3(int&) 인 함수 생성

}

//=================================
template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 3;

	// 1. 타입인자를 직접 전달하는 경우
	f4<int>(3);		// T=int	T&&=int&&		생성된함수: f4(int&& a)
	f4<int&>(n);	// T=int&	T&&=int& &&		생성된함수: f4(int&  a)
	f4<int&&>(3);	// T=int&&	T&&=int&& &&	생성된함수: f4(int&& a)

	// 2. 타입인자를 전달하지 않는 경우.
	// => 함수 인자를 보고 타입을 추론합니다.
	f4(n);	// 1) n은 int 이므로 T=int 로 결정하면 "f4(int&&)" 
			//		=> n 은 lvalue 이므로 받을수 없다. 에러

			// 2) T=int& 로 결정하면 T&&=int& && 이므로 "f4(int&)" 생성
			//		=> n 을 받을수 있다.

	f4(3);	// T=int 또는 T=int&& 로 결정하면 받을수 있는 함수 생성.
			// => C++ 표준은 "T=int" 로 추론하기로 결정.
			// => 인자는 T&&
			// => 생성된 함수는 "f4(int&&)" 생성
}