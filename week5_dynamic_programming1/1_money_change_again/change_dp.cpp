#include <iostream>
#include <vector>

using std::vector;
int get_change(int m,vector<int> &coins) {
    vector<int>table(m+1,0);
    table[0] = 0;
    for(int i=1; i<=m; i++){
    int minimum=999999;
        for(int j=0; j<coins.size(); j++){
            if (i >= coins[j])
            minimum = std::min(minimum, 1+table[i-coins[j]]);
        }
        table[i] = minimum;
    }
    return table[m];
}

int main() {
  int m;
  std::cin >> m;
  vector<int> coins{1,3,4};
  std::cout << get_change(m,coins) << '\n';
}
