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
	
	const int _size;
	int*      _arr;
};

int main()
{
	cout << "Hello world" << endl;
	return 0;
}

C::C(const int size) :
_size(size),
_arr(new int[size])
{
	cout << "Initial Constructor: " << _arr << endl;
}

C::C(const C &c) :
_size(c._size),
_arr(new int[c._size])
{
	memcpy(_arr, c._arr, sizeof(int) * _size);
	
	cout << "Copy Constructor: " << c._arr << " to " << _arr << endl;
}

C::C(C &&c) :
_size(c._size),
_arr(c._arr)
{
	c._arr = NULL;
	
	cout << "Move Constructor: " << _arr << endl;
}

C::~C()
{
	if(_arr != NULL)
		delete [] _arr;
	
	cout << "Destructor: " << _arr << endl;
}
