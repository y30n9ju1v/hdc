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
// 기반 클래스 보다, 멤버 데이타의 생성자를 먼저 초기화 하고 싶다면

// 1. 멤버 데이타만 담은 별도의 클래스를 만드세요
class PipeStreamBuffer
{
protected:
	Buffer buff{ 4096 }; 
};

// 2. Stream 보다 PipeStreamBuffer 를 먼저 상속받으세요
class PipeStream : public PipeStreamBuffer, public Stream
{
public:
	PipeStream() : Stream(buff) {}
};



int main()
{
	PipeStream ps;
}




