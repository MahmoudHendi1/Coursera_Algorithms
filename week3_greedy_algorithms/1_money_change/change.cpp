#include <iostream>

int get_change(int m) {
    int sum=0;
    sum+=m/10;
    m=m%10;
    sum+=m/5;
    m=m%5;
    sum+=m;
  return sum;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
