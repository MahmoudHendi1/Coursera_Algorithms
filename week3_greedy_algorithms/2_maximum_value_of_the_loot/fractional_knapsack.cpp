#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

double get_optimal_value(int capacity,  vector<pair<double,int> > Items) {
  double value = 0.0;
  int i=Items.size()-1;
  int amount;
    while(capacity>0){
    amount=std::min(Items[i].second,capacity);
    capacity-=amount;
    value+=amount*Items[i].first;
    i--;
    }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<pair<double,int> > Items(n);
  vector<double> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    Items[i]=std::make_pair(values[i]/weights[i],weights[i]);
  }
sort(Items.begin(),Items.end());
  double optimal_value = get_optimal_value(capacity, Items);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
