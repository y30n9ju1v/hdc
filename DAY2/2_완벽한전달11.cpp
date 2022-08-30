#include <iostream>

void f0()      { printf("f0\n"); }
void f1(int a) { printf("f1 : %d\n", a); }
int& f3(int a, double d, int& r) { r = 200; return r; }

// �Ϻ��� ������
// 1. ���� ���� ���ø����� �ϴ� ��찡 �����ϴ�.
// 2. ��ȯ ���� �Ϻ��ϰ� ���� �ַ��� "decltype(auto)" �� ��ȯ�ϸ� �˴ϴ�.
template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
//	StopWatch sw; // �� Ŭ���� �Ѱ� ���弼��
				  // 1. �����ڿ��� ���� �ð� ����ϼ���
				  // 2. �Ҹ��ڿ��� �ð� �ٽ� ���ؼ�, �����ڿ��� ����ѽð�
				  //    ���̸� ����ϼ���. (�Լ� ����ð� �Դϴ�.)
	return f( std::forward<T>(arg)... );
}

int main()
{
	int n = 0;
	chronometry(f0);
	chronometry(f1, 10);
	int& ret = chronometry(f3, 10, 3.4, n);
	ret = 300; // ret �� �ᱹ n�� ����
	std::cout << n << std::endl; // 300
}
