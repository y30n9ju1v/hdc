// T44. Use function templates to 
//      deduce class template argument types

template<typename T> T square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};

// List ���ø��� ��ü�� �����ϴ� �Լ����ø�
template<typename T>
List<T> make_list(int sz, T value)
{
	return List<T>(sz, value);
}


int main()
{
	// ������ ���� ���̴� ���� ?
	square<int>(3);	// ��Ȯ�� ǥ���
	square(3);		// Ÿ������ ��������, �׻� ���� ���Դϴ�.

	// Ŭ���� ���ø��� ���
	List<int> s1(10, 3);
//	List      s2(10, 3);	// �����ڸ� ���� Ÿ�� �߷��� C++17 ���� �����մϴ�

	auto s3 = make_list<int>(10, 3);	// Ÿ�� ����
	auto s4 = make_list(10, 3);		// �Լ� ���ø��� C++98 ����
									// Ÿ�� ��������.
}







