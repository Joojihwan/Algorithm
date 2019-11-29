#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find K'th smallest element in an array
int main()
{
	vector<int> a = { 7, 4, 6, 3, 9, 1 };
	const size_t k = 3;

	nth_element(a.begin(), a.begin() + k - 1, a.end());

	cout << "K'th smallest element in the array is " << a[k - 1];

	return 0;
}