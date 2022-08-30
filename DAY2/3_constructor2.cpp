#include <iostream>

// C.47: Define and initialize member variables 
//       in the order of member declaration

// 아래 클래스는 어떤 문제가 있을까요 ?
struct vector
{
	int* buff;
	int size;
public:
	// "멤버 초기화 리스트"의 실행순서는 이미 결정되어 있습니다.
	// 1. 기반 클래스가 있다면 기반 클래스 생성자
	// 2. 멤버 데이타는 "멤버 데이타의 선언 순서" 대로 실행
	// => buff 가 먼저 선언되었으므로 먼저 실행됩니다.
	//				 (2)		(1)
//	vector(int sz) : size(sz), buff(new int[size]) // new 할때 size 초기화안됨

	vector(int sz) : buff(new int[sz]), size(sz)  // 이코드가 좋은 코드
	{
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector v(10);
}