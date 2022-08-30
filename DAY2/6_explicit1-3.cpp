#include <iostream>

class vector
{
public:
	vector(int sz) { std::cout << "vector(int)" << std::endl; }
};

int main()
{
	vector v1( 10 );
	vector v2{ 10 };
}