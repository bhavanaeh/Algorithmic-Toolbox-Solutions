#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
unsigned long long fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current = 1;
    unsigned long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum(ll n)
{
    int res;
    
    if (n <= 1)
        return n;
    int periodicity = 60; //the pisano period for mod 10 is 60
    res = (fibonacci_sum_naive((n - 1) % periodicity) + fibonacci_sum_naive((n - 2) % periodicity) + 1);
    return res% 10;
    
}

int main() {
    ll n;
    cin >> n;
    cout << fibonacci_sum(n);
    return 0;
}