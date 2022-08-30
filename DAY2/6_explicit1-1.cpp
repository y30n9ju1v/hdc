// C46.인자가 한개인 생성자는 explicit 로 하는 것이 좋다.

class Vector
{
public:
	// 인자가 한개인 생성자는 되도록 이면"복사 초기화"를 금지하는 것이 좋습니다.
	
	// explicit 생성자 : 복사 초기화는 사용할수 없고, 직접 초기화만 가능
	explicit Vector(int sz) {}
};

void fn(Vector v) {}	

int main()
{
	Vector v1(10);	
	Vector v2 = 10;		// error

	// C++11
	Vector v3{ 10 };    
	Vector v4 = { 10 }; // error

	fn(10);	// error
	fn(v1); // ok. Vector(int) 가 아닌 복사 생성자 호출 입니다.
}

