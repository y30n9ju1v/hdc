// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const

// ���ڷ� ���� ���� �б⸸ �Ϸ��� �մϴ�.
// ������ ���� �ڵ�� ?
// int Ÿ���� ũ�Ⱑ �۰�, ���� ������/�Ҹ��ڵ� �����ϴ�
// => call by value(f1) �� �����ϴ�.
void f1(int n)        
{
	int x = n; // ���纻���� �ٷ� �а� �˴ϴ�.
}	
void f2(const int& n)  // �ᱹ�� ������ �Դϴ�.
{
	int x = n; // *p ó�� �޸𸮸� ���󰡼� �а� �˴ϴ�.
				// f1 �ڵ� ���� �����ϴ�.
}	// 2

int main()
{
	int a = 10;
	f1(a);
	f2(a);
}

// �Լ� ���ڸ� �޴� �⺻ ��å
// 1. ������ ���� �����Ϸ��� �Ҷ� (in/out parameter)
// => ������ �Ǵ� ���� ���
// 
// void inc1(int* p) { ++(*p);}
// void inc2(int& r) { ++r;}

// 2. ���ڰ��� �б⸸ �Ҷ�(in parameter )

// primitive type : call by value
// => f1(int n) {}

// user define type : const reference
// => f2( const std::string& s) {}