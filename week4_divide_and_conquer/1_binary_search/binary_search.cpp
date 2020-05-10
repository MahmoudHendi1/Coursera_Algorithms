#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(int left, int right, const vector<int> &a, int x) {
  int mid= left + (right-left)/2;
  if(left>right)
    return -1;
  if(a[mid]==x)
    return mid;
  if(a[mid]>x)
    return binary_search(left,mid-1,a,x);
  if(a[mid]<x)
    return binary_search(mid+1,right,a,x);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(0,a.size()-1,a,b[i]) << ' ';
    //std::cout << linear_search(a, b[i]) << ' ';
  }
}
