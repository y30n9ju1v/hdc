#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "���� ũ�� " << size << "�� �ʱ�ȭ" << std::endl;
	}
	~Buffer() { delete[] buff; }

	void useBuffer() { std::cout << "���� ���" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//-----------------------------
// Stream Ŭ������ ���� �Ļ��� Ŭ������ ����� ���ô�.

class PipeStream : public Stream
{
	Buffer buff{ 4096 }; // 4k ����.
public:
	// �����Ϸ��� ����� ����Ʈ ������ ���
	// => ��� Ŭ������ Stream �� ����Ʈ �����ڸ� ȣ���ϴ� �ڵ带 ����µ�
	//    Stream ���� ����Ʈ �����ڰ� ����.
//	PipeStream() : Stream() {}   

	// ��� Ŭ������ ����Ʈ �����ڰ� ������ �ݵ�� ���� �ٸ� �����ڸ� ȣ���ؾ� �մϴ�.
	PipeStream() : Stream( buff ) {}
	
	// �� �ڵ��� ������
	// => ��� ����Ÿ ���� ��� Ŭ���� �����ڰ� �׻� ���� ȣ��˴ϴ�
	// => buff �� �ʱ�ȭ �Ǳ� ���� Stream �� �����ؼ� ���˴ϴ�.
	// => ���� ��� ����Ÿ�� ��� Ŭ���� �����ڿ� ������ ������!!
};

int main()
{
	PipeStream ps;
}




