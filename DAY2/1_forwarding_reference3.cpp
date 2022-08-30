class X {};

// ��� 1. call by value
// => Ư¡(����) : ���纻 ��ü ����
//void foo(X arg) {}

// ��� 2. call by const lvalue reference
// => ���纻�� �������� ������
// => const �Ӽ��� �߰���.
// void foo(const X& arg) {}

// const �Ӽ��� �߰��� ���� ��� �ް� �ʹٸ� - C++98 �� �ȵ�
// => �׷��� "�Ϻ��� ����" ����� ����Ҽ� ����. 

// ��� 3. X&, X&& �� 2���� �Լ� ���� - C++11 ���� ����
// => ���纻�� ����, const �� �߰����� ���� ���·� ������ �ִ�.
// void foo(X&  arg) {}
// void foo(X&& arg) {}

// ��� 4. "���3"�� 2���� �Լ��� �ϴ� ���� ����(����)�ϴٸ�
//        "T&&" �� ����ϸ� �ڵ������Ҽ� �ִ�.
template<typename T> void foo(T&& arg)
{
}

int main()
{
	X x;

	// foo �Լ��� lvalue �� rvalue�� ��� ������ �ʹ�.
	foo(x);		// T=X&  T&&=X& &&   foo(X&) ����
	foo(X());   // T=X   T&&=X&&     foo(X&&)
}
