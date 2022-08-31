#include <iostream>

int main()
{
	// 1. 프로그램에서 사용되는 "값" 들을 리터럴(literal)이라고 합니다.
	// 2. 모든 리터럴은 타입이 있습니다.

	10;			// int
	3.4;		// double
	3.4f;		// float
	"hello";	// const char[6]
	true;		// bool 

	nullptr;	// std::nullptr_t    타입 입니다.
				//					우리가 만든 mynullptr_t와 비슷한 원리

	bool b = true; // 이 코드 처럼
	std::nullptr_t arg = nullptr; // 이렇게 변수를 만들어도 됩니다.

	// std::nullptr_t 타입은 우리가 만든 mynullptr_t  처럼
	// 모든 종류의 포인터로 암시적 형변환 됩니다.
	// 따라서, 이제 nullptr 대신 arg 사용해도 됩니다.

	int*    p1 = arg;
	double* p2 = arg;

}