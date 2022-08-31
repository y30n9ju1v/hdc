// nullptr 의 원리

void f1(int*  p) {}
void f2(char* p) {}

// nullptr 을 만들어 봅시다.
struct mynullptr_t
{
	// mynullptr_t => T* 로의 변환 허용
	// 즉, 모든 종류의 포인터로 암시적 형변환 가능.
	template<typename T>
	operator T* () { return 0; }
};

mynullptr_t mynullptr;

int main()
{
	f1(mynullptr);	// mynullptr_t 타입이 int* 로 암시적 변환되면 
					// 가능합니다.
					// 변환 연산자라는 멤버 함수가 있으면 됩니다.
					// "mynullptr.operator int*()"  라는 함수 검색
	f2(mynullptr);  // "mynullptr.operator char*()" 라는 함수 검색
}
