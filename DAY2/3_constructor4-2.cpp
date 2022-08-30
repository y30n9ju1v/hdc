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
// ��� Ŭ���� ����, ��� ����Ÿ�� �����ڸ� ���� �ʱ�ȭ �ϰ� �ʹٸ�

// 1. ��� ����Ÿ�� ���� ������ Ŭ������ ���弼��
class PipeStreamBuffer
{
protected:
	Buffer buff{ 4096 }; 
};

// 2. Stream ���� PipeStreamBuffer �� ���� ��ӹ�������
class PipeStream : public PipeStreamBuffer, public Stream
{
public:
	PipeStream() : Stream(buff) {}
};



int main()
{
	PipeStream ps;
}




