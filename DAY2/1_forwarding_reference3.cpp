class X {};

// 방법 1. call by value
// => 특징(단점) : 복사본 객체 생성
//void foo(X arg) {}

// 방법 2. call by const lvalue reference
// => 복사본은 생성되지 않지만
// => const 속성이 추가됨.
// void foo(const X& arg) {}

// const 속성의 추가도 없이 모두 받고 싶다면 - C++98 은 안됨
// => 그래서 "완벽한 전달" 기술을 사용할수 없음. 

// 방법 3. X&, X&& 의 2개의 함수 제공 - C++11 부터 가능
// => 복사본도 없고, const 도 추가되지 않은 상태로 받을수 있다.
// void foo(X&  arg) {}
// void foo(X&& arg) {}

// 방법 4. "방법3"의 2개의 함수가 하는 일이 동일(유사)하다면
//        "T&&" 를 사용하면 자동생성할수 있다.
template<typename T> void foo(T&& arg)
{
}

int main()
{
	X x;

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(x);		// T=X&  T&&=X& &&   foo(X&) 생성
	foo(X());   // T=X   T&&=X&&     foo(X&&)
}
