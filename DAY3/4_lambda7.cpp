// conversion function pointer

int main()
{
	// ĸ������ ���� ���� ǥ���ĸ� �Լ� ������ ��ȯ �����մϴ�.
	int(*f1)(int, int) = [](int a, int b) { return a + b; };


	int num = 10;
	int(*f2)(int, int) = [num](int a, int b) { return a + b + num; };
					// error.
}