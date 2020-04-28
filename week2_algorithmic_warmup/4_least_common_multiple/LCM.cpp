#include <iostream>
#include <vector>
typedef long long int   ll;
using namespace std;
//using the formula hcf*lcm=n1*n2

ll hcf(ll a, ll b)
{
    if (b == 0)
        return a;
    else
    {
        ll x = a % b;
        return(hcf(b, x));
    }
}

ll lcm(ll a, ll b) {
    
    return (a*b)/hcf(a,b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b);
    return 0;
}