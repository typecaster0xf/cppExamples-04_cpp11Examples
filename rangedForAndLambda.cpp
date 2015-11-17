#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename Op>
void vectorOp(vector<T> v, Op op);

int main()
{
	vector<unsigned int> v =
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	auto printV = [](unsigned int u)
	{
		cout << u << ' ';
		return;
	};
	
	cout << hex;
	vectorOp(v, printV);
	cout << endl;
	
	const unsigned int elementToPrint = 13;
	void (*printOne)(unsigned int u) = [&](unsigned int u)
	{
		if(u == elementToPrint)
			cout << u << ' ';
		return;
	};
	
	vectorOp(v, printOne);
	cout << endl;
	
	return 0;
}

template <typename T, typename Op>
void vectorOp(vector<T> v, Op op)
{
	for(auto i : v)
		op(i);
	
	return;
}
