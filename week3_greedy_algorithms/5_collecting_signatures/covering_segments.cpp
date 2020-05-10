#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::pair;


vector<int> optimal_points(vector<pair<int,int> > &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end());
  int i=0;
  while(i<segments.size()){
    int end= segments[i].second;
    while(i<segments.size() && end>=segments[i].first){
        end=std::min(end,segments[i].second);
        i++;
    }
    points.push_back(end);
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<pair<int,int> > segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
