// F16 ~ F20  ( 10 page ~)
// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const
// F.18 : For "will-move-from" parameters, pass by X&& and std::move the parameter
// F.19 : For "forward" parameters, pass by TP&& and only std::forward the parameter
// F.20 : For "out" output values, prefer return values to output parameters

#include <iostream>
#include <string>

struct Rect
{
	int left, top, right, bottom;
};
// call by value : user type�� ����ϴ� ���� ���� �ʽ��ϴ�
// ���� 1. ���纻�� �����ϹǷ� �޸� �������
//     2. ��������ڿ� �Ҹ��� ȣ�⿡ ���� �Լ� ȣ���� �������
//     3. �Ϻ� Ŭ������ ���� ���� �ڿ��� �ڿ� ���翡 ���� �������
//void f1(Rect rc) {}
//void f2(std::string s2) {}

// ���� �б⸸ �Ѵٸ� �ݵ�� const ���̼���
// �׷���, �ӽð�ü�� ������ �ֽ��ϴ�.
void f1(const Rect& rc)        {}
void f2(const std::string& s2) {}

int main()
{
	Rect rc;
	f1(rc);

	std::string s1 = "to be or not to be";
	f2(s1);
}
