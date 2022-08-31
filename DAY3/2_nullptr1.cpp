// ES.47: Use nullptr rather than 0 or NULL - C++11 이후 권장

int main()
{
	int* p1 = 0;		// bad
	int* p2 = nullptr;	// good

	// 장점 1. 가독성이 좋습니다.
	auto ret = fn();

	if (ret == 0) {}		// 이 코드만으로 ret가 포인터 인지 정수인지 알수 없다.
	if (ret == nullptr) {}	// ret가 포인터 라고 예측 가능
}
