#include <iostream>
#include <vector> 
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>v;
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int max1 = -1, max2 = -1;
	long long prod = 0;
	for (i = 0; i < n; i++)
	{
		if (v[i] > v[max1] || max1 == -1)
			max1 = i;
	}
	for (j = 0; j < n; j++)
	{
		if (max2 == -1 || v[i] > v[max2] && max1 != i)
			max2 = i;
	}
	prod = v[max1] * v[max2];
	cout << prod;
	return 0;




}