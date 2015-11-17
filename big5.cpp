#include <cstring>
#include <iostream>

using namespace std;

class C
{
public:
	
	C(const int size);
	C(const C &c);
	C(C &&c);
	~C();
	
protected:
	
	const int size;
	int *arr;
};

int main()
{
	cout << "Hello world" << endl;
	return 0;
}

C::C(const int size) :
size(size),
arr(new int[size])
{
	cout << "Initial Constructor: " << arr << endl;
}

C::C(const C &c) :
size(c.size),
arr(new int[c.size])
{
	memcpy(arr, c.arr, sizeof(int) * size);
	
	cout << "Copy Constructor: " << c.arr << " to " << arr << endl;
}

C::C(C &&c) :
size(c.size),
arr(c.arr)
{
	c.arr = NULL;
	
	cout << "Move Constructor: " << arr << endl;
}

C::~C()
{
	if(arr != NULL)
		delete [] arr;
	
	cout << "Destructor: " << arr << endl;
}
