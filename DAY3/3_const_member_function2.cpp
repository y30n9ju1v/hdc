// 상수 멤버 함수는 선택이 아닌 "필수 문법" 입니다.

// 객체의 상태를 변경하지 않은 모든 멤버 함수(getter) 는

// "반드시 상수 멤버 함수"로 해야만 됩니다.

// 아래 getArea() 에 const 붙이지 않는 것은 "틀린 코드" 입니다.

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};

//void foo(Rect r)		// call by value : 복사본의 오버헤드!!!

void foo( const Rect& r)	// 이코드가 좋은 코드!!!
{
	int n = r.getArea(); //????
}

int main()
{
	Rect r(1, 2, 3, 4);		// 상수객체 아닙니다.

	int n = r.getArea();	// ok.
	
	foo(r);
}