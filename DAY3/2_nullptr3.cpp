#include <iostream>
#include <vector>

class Object
{
public:
	Object(int n, int* p) {}
};

int main()
{
	std::vector<Object> v;

	// 1. ��ü�� ������ �� �ֱ�
	Object obj(0, 0);  //  ok
	v.push_back(obj);

	// 2. ��ü�� �����ϱ� ���� ������ ���ڸ� �����ϱ� - emplace!!!
//	v.emplace_back(0, 0); // error
	v.emplace_back(0, nullptr); // ok..

	// �� ó�� 0�� ���� �����ͺ����� ������ ���� �ƴ϶�
	// �ٸ����� �� ���ļ� ����(�Ϻ��� ����) �Ҷ��� 0�� ������ �����ϴ�
	// �׷���, nullptr�� ����� �Դϴ�.
}




