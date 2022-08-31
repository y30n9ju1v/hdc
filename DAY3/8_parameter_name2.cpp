// E.25: If you can't throw exceptions, simulate RAII for resource management
// CP.20: Use RAII, never plain lock() / unlock()
// F.9: Unused parameters should be unnamed

#include <iostream>
#include <mutex>

// 함수 오버로딩(함수인자)에 사용하기 위한 empty class 설계
struct adopt_lock_t {};

adopt_lock_t adopt_lock;

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m)				 : mtx(m) { mtx.lock(); }
	lock_guard(T& m, std::adopt_lock_t) : mtx(m) {  }
	~lock_guard()			                  { mtx.unlock(); } 
};

std::mutex m;
int shared_data = 0;

void foo()
{
	// C++ 표준에는 뮤텍스를 획득하는 방법이
	// lock 말고 다른 방법도 몇개 있습니다.
	if ( m.try_lock() )
	{
		// m 은 이미 lock 을 획득했습니다.
		// 그런데, unlock 은 안전하게 하기 위해 RAII 를 사용하고 싶습니다.
		lock_guard<std::mutex> g(m, std::adopt_lock);

		//.....

	}
}

int main()
{

}