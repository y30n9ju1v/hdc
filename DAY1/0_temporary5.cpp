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

};

int main()
{
	Counter c;
//	c.increment();
//	c.increment();
//	c.increment();
	c.increment().increment().increment();

	std::cout << c.get() << std::endl;
}
