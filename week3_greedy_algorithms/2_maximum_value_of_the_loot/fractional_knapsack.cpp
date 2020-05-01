#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_max(vector <int> weights, vector <int> values)
{
    int maxi = 0;
    double fmax = 0;
    int i, len = values.size();
    for (i = 0; i < len; i++)
    {
        if (weights[i] != 0 && (double)values[i] / weights[i] > fmax)
        {
            fmax = (double)values[i] / weights[i];
            maxi = i;
        }
    }
    return maxi;
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    // write your code here
    int i;
    int len = values.size();
    for (i = 1; i <= len; i++)
    {
        if (capacity == 0)
            return value;
        int index;
        index = get_max(weights, values);
        int fmin;
        fmin = min(capacity, weights[index]);
        value = value + fmin * (double)values[index] / weights[index];
        weights[index] = weights[index] - fmin;
        capacity = capacity - fmin;

    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
