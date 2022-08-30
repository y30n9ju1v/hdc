#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

int main()
{
	int n = 0;
	chronometry(foo, 10);
	chronometry(goo, n);
}
