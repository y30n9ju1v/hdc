// F.19: For ��forward�� parameters, pass by TP&& and only std::forward the parameter

template<typename T> void foo(T a)
{
	T& r = a;	// int& &r = a;
				// int& r = a;
}


int main()
{
	int n = 10;

	int&  r1 = n ; // lvalue reference
	int&& r2 = 10; // rvalue reference 

	// �ٽ� 1. �������� �����ʹ� ����� ������
	//        reference �� reference�� ����� �����ϴ�.
//	int* *p;		// �������� �����ʹ� ����� �ֽ��ϴ�.
//	int& & r3 = ? ; // reference �� reference.. error


	// �ٽ� 2. Ÿ���߷� �������� �߻��ϴ� reference �浹��
	//		 ������ �ƴ϶� "reference collapsing" ��Ģ�� ���� �����ȴ�.

	using LREF = int&; // typedef int& LREF;
	using RREF = int&&;

	LREF r4 = n ;
	RREF r5 = 10;

	// �ٽ� 3. "reference collapsing" ��Ģ �ܿ켼��.
	// => ���ø� ���鶧 �ַ� ����մϴ�.
	LREF& r6 = n ;  // int&  &		=> int&
	RREF& r7 = n ;  // int&& &		=> int&
	LREF&& r8 = n ; // int&  &&		=> int&
	RREF&& r9 = 10;	// int&& &&		=> int&&

	// ex) 
	foo<int&>(n);
}





