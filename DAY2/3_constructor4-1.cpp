#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "버퍼 크기 " << size << "로 초기화" << std::endl;
	}
	~Buffer() { delete[] buff; }

	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//-----------------------------
// Stream 클래스로 부터 파생된 클래스를 만들어 봅시다.

class PipeStream : public Stream
{
	Buffer buff{ 4096 }; // 4k 버퍼.
public:
	// 컴파일러가 만드는 디폴트 생성자 모양
	// => 기반 클래스인 Stream 의 디폴트 생성자를 호출하는 코드를 만드는데
	//    Stream 에는 디폴트 생성자가 없다.
//	PipeStream() : Stream() {}   

	// 기반 클래스에 디폴트 생성자가 없으면 반드시 직접 다른 생성자를 호출해야 합니다.
	PipeStream() : Stream( buff ) {}
	
	// 위 코드의 문제점
	// => 멤버 데이타 보다 기반 클래스 생성자가 항상 먼저 호출됩니다
	// => buff 가 초기화 되기 전에 Stream 에 전달해서 사용됩니다.
	// => 절대 멤버 데이타를 기반 클래스 생성자에 보내지 마세요!!
};

int main()
{
	PipeStream ps;
}




