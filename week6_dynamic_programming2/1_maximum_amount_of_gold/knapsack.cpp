#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
vector<vector <int> > knapsack(w.size()+1,vector<int>(W+1) );

    for(int j=0;j<=W;j++)
        knapsack[0][j]=0;

    for(int i=0;i<=w.size();i++)
        knapsack[i][0]=0;

    for(int i=1;i<=w.size();i++)
        for(int j=1;j<=W;j++)
            if(w[i-1]<=j)
                knapsack[i][j]=std::max(knapsack[i-1][j],w[i-1]+knapsack[i-1][j-w[i-1]]);
            else
                knapsack[i][j]=knapsack[i-1][j];


    return knapsack[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
