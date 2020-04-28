#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
ll fibonacci_sum(ll n) {
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current = 1;

    for (ll i = 0; i < n - 1; ++i) {
        ll tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current + 1) % 10;
    }

    return current;
}
ll get_fibonacci_partial_sum_fast(ll from, ll to) {
    if (from == 0)
        from = 1;
    
    int periodicity = 60;

    ll sumto = fibonacci_sum((to) % periodicity);
    ll sumfrom = fibonacci_sum((from - 1) % periodicity);
    ll diff = sumto - sumfrom;
    return (diff + 10) % 10;
}
int main() {
    ll from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
