#include <iostream>

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}
long long lcm_naive(int a, int b) {
  return (1ll*a* b)/gcd(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
