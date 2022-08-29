// F.43: Never(directly or indirectly) return a pointer or a reference to a local object
// F.44 : Return a T & when copy is undesirable and "returning no object" isn't needed

// primitive 타입의 참조 반환

int x = 10;

int  f1() { return x; } // x의 값 "10" 을 반환. rvalue 반환
int& f2() { return x; } // x자체를 반환(별명)

int main()
{
	int ret = f1();

//	f1() = 20; // error. 10 = 20
	f2() = 20; // ok. 
				// 참조를 반환하면 등호의 함수 호출이
				// 등호의 왼쪽에 놓일수 있습니다.
}
// 정리
int   fn() { return x;} // x가 아닌 x의 값 반환
Point fn() { return pt; } // pt의 복사본객체(temporary)반환