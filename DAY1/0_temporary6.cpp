// F.43: Never(directly or indirectly) return a pointer or a reference to a local object
// F.44 : Return a T & when copy is undesirable and "returning no object" isn't needed

// primitive Ÿ���� ���� ��ȯ

int x = 10;

int  f1() { return x; } // x�� �� "10" �� ��ȯ. rvalue ��ȯ
int& f2() { return x; } // x��ü�� ��ȯ(����)

int main()
{
	int ret = f1();

//	f1() = 20; // error. 10 = 20
	f2() = 20; // ok. 
				// ������ ��ȯ�ϸ� ��ȣ�� �Լ� ȣ����
				// ��ȣ�� ���ʿ� ���ϼ� �ֽ��ϴ�.
}
// ����
int   fn() { return x;} // x�� �ƴ� x�� �� ��ȯ
Point fn() { return pt; } // pt�� ���纻��ü(temporary)��ȯ