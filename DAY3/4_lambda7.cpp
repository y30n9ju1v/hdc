// conversion function pointer

int main()
{
	// 캡쳐하지 않은 람다 표현식만 함수 포인터 변환 가능합니다.
	int(*f1)(int, int) = [](int a, int b) { return a + b; };


	int num = 10;
	int(*f2)(int, int) = [num](int a, int b) { return a + b + num; };
					// error.
}