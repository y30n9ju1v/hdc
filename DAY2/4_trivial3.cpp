#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;

	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

	// ����ڰ� ���� �����ڸ� �����
	// => ������ ��� ����� ���� ���� �ϴ� �θ� �˷��� ����̶�
	// => �����Ϸ� �������� trivial ���� �ʴٰ� �����ϰ� �˴ϴ�
//	Point(const Point& p) : x(p.x), y(p.y) {}

	// ���� : ����Ʈ ������ �ʿ� �ϸ� �ݵ��  "=default" �� ��û�ϼ���
	//       => ���� ������ ������(trivial ���� �ʽ��ϴ�.)
	//	     => move �����ڸ� ���� �����, ���� �����ڴ� ���� �˴ϴ�.
	//       => Ȥ�� ����Ʈ ���簡 �ʿ� �ߴٸ� "=default"�� �ϼ���.
	Point(const Point& p) = default;
};



// ���� Ÿ���� �迭�� �����ϴ� copy �� ������ ���ô�.
template<typename T> 
void copy(T* dst, T* src, std::size_t size)
{
	// ���� �����ڰ� trivial(��� ����� ���� ����)�Ѱ��� ����
	// �ٸ� ����
	if (std::is_trivially_copy_constructible<T>::value)
	{
		std::cout << "memcpy ���" << std::endl;
		memcpy(dst, src, sizeof(T) * size);
	}
	else
	{
		std::cout << "�� ��ü�� ��������ڸ� ȣ���ؼ� ����" << std::endl;
		while (size--)
		{
			new(dst) T(*src); // ���� ���ϴ�.
			++dst, ++src;
		}
	}
}

int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];

	
	copy(pt2, pt1, 5);

}