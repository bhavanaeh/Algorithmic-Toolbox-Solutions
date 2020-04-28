#include <iostream>
#include <vector>
typedef long long int   ll;
using namespace std;
ll periodicity(ll m)
{
	ll a = 0, b = 1, c = a + b;
	int i;
	for (i = 0; i < m * m; i++)
	{
		c = (a + b) % m;
		a = b;
		b = c;
		if (a == 0 && b == 1)//start value reached i.e. repetation starts
		{
			return (i + 1);
		}

	}
}
ll fibonacci_huge(ll n, ll m)
{
	if (n <= 1)
		return n;

	ll rem = n % periodicity(m);
	ll x = 0, y = 1, res = rem;
	int j;
	for (j = 1; j < rem; j++)
	{
		res = (x + y) % m;
		x = y;
		y = res;

	}
	return res % m;
}
int main()
{
	ll n, m;
	cin >> n >> m;
	cout << fibonacci_huge(n, m);
}