#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> partition3(vector<int> &a, int l, int r) {
  vector <int> res(2);
  int lt=l;
  int gt=r;
  int i=l; //for scanning the array from left to right
  int pivot = a[l];
  while(i<=gt)
  {
    if(a[i]<pivot)
    {
      swap(a[lt],a[i]);
      lt+=1;
      i+=1;
    }
    else if(a[i]>pivot)
    {
      swap(a[gt],a[i]);
      gt-=1;
    }
    else//a[i]==pivot
    {
      i+=1;
    }
    res[0]=lt;
    res[1]=gt;
  }
  return res;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
