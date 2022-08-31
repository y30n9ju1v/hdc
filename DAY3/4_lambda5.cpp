// F.53: Avoid capturing by reference in lambdas that will be used non - locally, 
//       including returned, stored on the heap, or passed to another thread

#include <vector>
#include <functional>

std::function<int(int, int)> f;

void foo()
{

}

int main()
{
	
}