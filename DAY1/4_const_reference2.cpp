// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const

// 인자로 받은 값을 읽기만 하려고 합니다.
// 다음중 좋은 코드는 ?
// int 타입은 크기가 작고, 복사 생성자/소멸자도 없습니다
// => call by value(f1) 이 좋습니다.
void f1(int n)        
{
	int x = n; // 복사본에서 바로 읽게 됩니다.
}	
void f2(const int& n)  // 결국은 포인터 입니다.
{
	int x = n; // *p 처럼 메모리를 따라가서 읽게 됩니다.
				// f1 코드 보다 느립니다.
}	// 2

int main()
{
	int a = 10;
	f1(a);
	f2(a);
}

// 함수 인자를 받는 기본 정책
// 1. 인자의 값을 수정하려고 할때 (in/out parameter)
// => 포인터 또는 참조 사용
// 
// void inc1(int* p) { ++(*p);}
// void inc2(int& r) { ++r;}

// 2. 인자값을 읽기만 할때(in parameter )

// primitive type : call by value
// => f1(int n) {}

// user define type : const reference
// => f2( const std::string& s) {}