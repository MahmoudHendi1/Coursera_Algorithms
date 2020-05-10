#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int total = 0;
  int increment = 1;
  int count = 0;

while (total + increment <= n){
    total += increment;
    summands.push_back(increment);
    increment++;
    count++;
}
summands[count-1] += n - total;

  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
