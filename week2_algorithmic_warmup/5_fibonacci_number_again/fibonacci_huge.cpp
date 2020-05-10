#include <iostream>
#include <math.h>
#include <vector>
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}
long long fibonacci_fast(long long n, long long m) {
    int end = n%get_pisano_period(m);
    std::vector<long long> F(end+1);
    if(n<=1){
    return n;
    }
    F[0]=0;
    F[1]=1;
    for(int i=2;i<=end;i++){
        F[i]=(F[i-1]+F[i-2])%m;
    }
    return F[end]%m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_fast(n, m) << '\n';
}
