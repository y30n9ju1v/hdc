#include <iostream>

// F.44: Return a T & when copy is undesirable and "returning no object" isn't needed

class Counter
{
	int value{ 0 };
public:
	Counter increment()
	{
		++value;
		return *this;
	}
	int get() const { return value; }

	Counter(const Counter& c) :value(c.value)
	{
		std::cout << "Counter Copy ctor" << std::endl;
	}
	~Counter()
	{
		std::cout << "~Counter" << std::endl;
	}
	Counter() = default;
};
int main()
{
	Counter c;
//	c.increment();
//	c.increment();
//	c.increment();
	std::cout << "------------------" << std::endl;
	c.increment().increment().increment();
	std::cout << "------------------" << std::endl;
	std::cout << c.get() << std::endl;
}
