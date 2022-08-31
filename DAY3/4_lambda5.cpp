
// F.53: Avoid capturing by reference in lambdas 
//       that will be used non - locally, 
//       including returned, stored on the heap, or passed to another thread

#include <vector>
#include <functional>

// ���� ǥ���Ŀ� ���� �����Ϸ��� �ڵ� ������ Ŭ������ �ٸ� ���ƿ��� �� �����ֳ���?

std::function<int(int, int)> f; // �������� �̸��� ��� �Լ� �� ��밡��

void foo()
{
	int num = 10;
	f = [&num](int a, int b) { return a + b + num; };

}	// <== num �ı�. f �� �����ϴ� ������ dangling!

void goo()
{
	int ret = f(1, 2); // ����.. f�� dangling reference ����
}



int main()
{
	int num = 10;

	// �ٽ� 1. value capture, reference capture
//	auto f1 = [num](int a) { num = 20; return num + a; }; // error
				// => ���������� num �� ��. 10 ����
				// => ���پȿ��� "num = 20" ���� ����

	auto f2 = [&num](int a) { num = 20;  return num + a; }; // ok
				// => num �� ������ ����

	f2(0);

	std::cout << num << std::endl;

	// �ٽ� 2. ����ǥ������ auto �� �ƴ϶� std::function ����Ƶ� �˴ϴ�.
	auto f3 = [](int a, int b) {return a + b; };

	std::function<int(int, int)> f4 = [](int a, int b) {return a + b; };
}