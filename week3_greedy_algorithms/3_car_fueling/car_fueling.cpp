#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops[stops.size()-1]=dist;
    int refills=0,i=1;
    int L=0;
    while(i<stops.size()){
        while(i<stops.size() && stops[i]-L<=tank)
            i++;
        L=stops[i-1];
        if(i>=stops.size())
            return refills;
        if(stops[i]-stops[i-1]>tank)
            return -1;
        refills++;
    }
    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    stops[0]=0;
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
