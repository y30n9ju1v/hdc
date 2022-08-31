// T44. Use function templates to 
//      deduce class template argument types

template<typename T> T square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};

// List 템플릿의 객체를 생성하는 함수템플릿
template<typename T>
List<T> make_list(int sz, T value)
{
	return List<T>(sz, value);
}


int main()
{
	// 다음중 쉬워 보이는 것은 ?
	square<int>(3);	// 정확한 표기법
	square(3);		// 타입인자 생략가능, 항상 쉬워 보입니다.

	// 클래스 템플릿의 경우
	List<int> s1(10, 3);
//	List      s2(10, 3);	// 생성자를 통한 타입 추론은 C++17 부터 가능합니다

	auto s3 = make_list<int>(10, 3);	// 타입 전달
	auto s4 = make_list(10, 3);		// 함수 템플릿은 C++98 부터
									// 타입 생략가능.
}







