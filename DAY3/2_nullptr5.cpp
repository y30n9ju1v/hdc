#include <iostream>

int main()
{
	// 1. ���α׷����� ���Ǵ� "��" ���� ���ͷ�(literal)�̶�� �մϴ�.
	// 2. ��� ���ͷ��� Ÿ���� �ֽ��ϴ�.

	10;			// int
	3.4;		// double
	3.4f;		// float
	"hello";	// const char[6]
	true;		// bool 

	nullptr;	// std::nullptr_t    Ÿ�� �Դϴ�.
				//					�츮�� ���� mynullptr_t�� ����� ����

	bool b = true; // �� �ڵ� ó��
	std::nullptr_t arg = nullptr; // �̷��� ������ ���� �˴ϴ�.

	// std::nullptr_t Ÿ���� �츮�� ���� mynullptr_t  ó��
	// ��� ������ �����ͷ� �Ͻ��� ����ȯ �˴ϴ�.
	// ����, ���� nullptr ��� arg ����ص� �˴ϴ�.

	int*    p1 = arg;
	double* p2 = arg;

}