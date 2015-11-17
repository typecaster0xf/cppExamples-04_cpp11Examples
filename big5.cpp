#include <cstring>
#include <iostream>

using namespace std;

class C
{
public:
	
	C();
	C(const int size);
	C(const C &c);
	C(C &&c);
	~C();
	
	C& operator=(const C &c);
	C& operator=(C &&c);
	
	friend
	ostream& operator<<(ostream& sout, const C c);
	
protected:
	
	const int _size;
	int*      _arr;
};

C makeC()
{
	C c(6);
	
	return c;
}

int main()
{
	cout << makeC() << endl;
	return 0;
}

C::C() :
_size(0),
_arr(NULL)
{
	cout << "Default Constructor" << endl;
}

C::C(const int size) :
_size(size),
_arr(new int[size])
{
	for(int j = 0; j < _size; j++)
		_arr[j] = j;
	
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

C& C::operator=(const C &c)
{
	cout << "Copy Assignment Operator" << endl;
	
	int* mySize = const_cast<int*>(&_size);
	
	if(_arr != NULL)
		delete [] _arr;
	
	*mySize = c._size;
	_arr    = new int[c._size];
	memcpy(_arr, c._arr, sizeof(int) * c._size);
	
	return *this;
}

C& C::operator=(C &&c)
{
	cout << "Move Assignment Operator" << endl;
	
	int* mySize = const_cast<int*>(&_size);
	*mySize     = c._size;
	_arr        = c._arr;
	c._arr      = NULL;
	
	return *this;
}

ostream& operator<<(ostream& sout, const C c)
{
	for(int j = 0; j < c._size; j++)
		sout << c._arr[j] << ' ';
	return sout;
}
