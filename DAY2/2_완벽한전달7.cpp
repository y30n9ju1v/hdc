#include <iostream>

class X
{
public:
	X() = default; // ����Ʈ ������ ��û

	X(const X&)     { std::cout << "COPY ������" << std::endl; }
	X(X&&) noexcept { std::cout << "MOVE ������" << std::endl; }
};
// �ٽ� 1. T& �� T&& �� �������� ���� �ϼ���
// T&  : ���� Ÿ���� lvalue �� ���� �ްڴٴ� �ǵ�
// T&& : ���� Ÿ���� lvalue, rvalue �� ��� ���� �ްڴٴ� �ǵ�

// �ٽ� 2. std::move() �� std::forward() �� �������� �Ϻ��� ���� �ϼ���

template<typename T> void fn(T&& arg)
{
	T obj = arg;
}
int main()
{
	X x;
	fn(x);   // lvalue ����
	fn(X()); // rvalue ����
}