// E.25: If you can't throw exceptions, simulate RAII for resource management
// CP.20: Use RAII, never plain lock() / unlock()
// F.9: Unused parameters should be unnamed

#include <iostream>
#include <mutex>

// lock/unlock 을 RAII 로 관리하기 위한 클래스 - 이미 C++ 표준에 있습니다.
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); } // 소멸자가 throw 하면
												// 안됩니다.
												// C++ 규칙, 소멸자는 예외가
												// 없어야 한다.
};


std::mutex m;
int shared_data = 0;

// 2개의 스레드가 foo 를 동시에 실행한다고 생각 해보세요.
void foo()
{
	{
		std::lock_guard<std::mutex> g(m); // RAII 를 사용한 lock/unlock

		// 이제 실행중에 "예외가 나와도" g의 소멸자는 호출된다는 보장이 있습니다.
		// 따라서, 항상 unlock 이 됨을 보장 합니다.
	//	m.lock();
		shared_data = 100;
		// 예외 발생..
	//	m.unlock();
	}
	//....
}


int main()
{

}