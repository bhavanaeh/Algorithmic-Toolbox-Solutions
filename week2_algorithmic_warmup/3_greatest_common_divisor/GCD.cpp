#include <iostream>
#include <vector>
typedef long long int   ll;
using namespace std;
ll gcd(ll a, ll b) {
    ll current_gcd = 1;
    if (b == 0)
        return a;
    else
    {
        ll x = a % b;

        return (gcd(b, x));
    }
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}
