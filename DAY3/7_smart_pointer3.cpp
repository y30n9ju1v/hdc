// R.11: Avoid calling new and delete explicitly
// R.1: Manage resources automatically using resource handles and RAII (Resource Acquisition Is Initialization)
// E.6: Use RAII to prevent leaks

#include <iostream>
#include <memory>

int main()
{
	int* p = new int;		// delete 가 필요 하지만

	std::shared_ptr<int> sp1(p);	// 스마트포인터에 넘기면
									// sp1이 파괴시 자동 delete 됩니다.
	std::shared_ptr<int> sp2 = sp1; // 문제 없습니다.

	std::shared_ptr<int> sp3(p); // ???

	// 핵심 1. 자원을 만들고 raw pointer 에 담은후에 스마트포인터에 보내지마세요
	int* p2 = new int;
	std::shared_ptr<int> sp4(p2); // 아주 나쁜 코드!!	
								// raw pointer p2자체를 절대 만들지 마세요

	// 핵심 2. 자원을 할당하는 시점은 "자원 관리객체를 만들때" 입니다.
	// "RAII :  Resource Acquision Is (자원관리객체가) Initialization"
	std::shared_ptr<int> sp5(new int); // 위보다 좋은 코드

	std::shared_ptr<int> sp6 = std::make_shared<int>(0); //0은 초기값
}
