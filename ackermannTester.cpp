#include <iostream>
#include "ackermann.h"

using namespace std;

int main()
{
	cout << ackermann(1, 1) << '\n'
			<< ackermann(2, 15) << endl;
	
	return 0;
}
