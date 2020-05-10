#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  vector<long long> arr(n+1);
arr[0]=0;
arr[1]=0;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0){
            arr[i] = std::min(1 + arr[i / 2], arr[i]);
        }
        if (i % 3 == 0){
            arr[i] = std::min(1 + arr[i / 3], arr[i]);
        }
    }
    int ind=n;
    for (int i = n; i > 0;) {
        sequence.push_back(ind);
        ind = i-1;
        int mn=arr[i-1];
        if (i % 2 == 0 && mn > arr[i / 2]){
            ind=i/2;
            mn=arr[ind];
        }
        if (i % 3 == 0&& mn > arr[i / 3]){
            ind=i/3;
            mn=arr[ind];
        }
        i=ind;
    }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
