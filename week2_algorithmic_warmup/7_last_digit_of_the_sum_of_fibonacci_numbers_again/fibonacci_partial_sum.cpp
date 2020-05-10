#include <iostream>
#include <vector>
#include <math.h>
using std::vector;

long long fibonacci_fast(long long m,long long n) {
    n = (n)%60;
    std::vector<int> F(n+1);

    F[0]=0;
    F[1]=1;
    int sum=0;
    for(int i=2;i<=m;i++){
        F[i]=(F[i-1]%10+ F[i-2]%10)%10;
    }
    sum=F[m];
    for(int i=std::max(m+1,2ll);i<=n;i++){
        F[i]=(F[i-1]%10+ F[i-2]%10)%10;
        sum=(sum+F[i])%10;
    }
    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_fast(from ,to) << '\n';
}
