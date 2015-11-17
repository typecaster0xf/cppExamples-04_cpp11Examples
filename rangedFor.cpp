#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<unsigned int> v =
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	cout << hex;
	for(auto i : v)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}
