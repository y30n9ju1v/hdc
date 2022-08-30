// C46.인자가 한개인 생성자는 explicit 로 하는 것이 좋다.

class Vector
{
public:
	Vector(int sz) {}
};

//void fn(Vector v) {}	// Vector v = 10;
void fn(const Vector& v) {}	// 이코드는 10을 받을수 있습니다.

int main()
{
	// 핵심 1. 용어 알아 두세요
	// 생성자 인자로 int 를 한개 받으면 아래처럼 4가지 형태로 객체생성이 됩니다.
	// C++98
	Vector v1(10);	// direct(직접) initialization : =이 없는 경우
	Vector v2 = 10; // copy(복사)   initialization : =이 있는 경우

	// C++11
	Vector v3{ 10 };    // direct(직접) initialization : =이 없는 경우
	Vector v4 = { 10 }; // copy(복사)   initialization : =이 있는 경우

	// 핵심 2. 함수의 인자 전달은 "복사 초기화" 입니다.
	fn(10);	// 의미상 잘못된 코드 입니다. 에러나오는것이 좋습니다.
	fn(v1);
}

