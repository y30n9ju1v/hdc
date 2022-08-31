// nullptr �� ����

void f1(int*  p) {}
void f2(char* p) {}

// nullptr �� ����� ���ô�.
struct mynullptr_t
{
	// mynullptr_t => T* ���� ��ȯ ���
	// ��, ��� ������ �����ͷ� �Ͻ��� ����ȯ ����.
	template<typename T>
	operator T* () { return 0; }
};

mynullptr_t mynullptr;

int main()
{
	f1(mynullptr);	// mynullptr_t Ÿ���� int* �� �Ͻ��� ��ȯ�Ǹ� 
					// �����մϴ�.
					// ��ȯ �����ڶ�� ��� �Լ��� ������ �˴ϴ�.
					// "mynullptr.operator int*()"  ��� �Լ� �˻�
	f2(mynullptr);  // "mynullptr.operator char*()" ��� �Լ� �˻�
}
