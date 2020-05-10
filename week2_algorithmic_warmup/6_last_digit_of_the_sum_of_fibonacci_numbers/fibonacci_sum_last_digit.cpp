#include <iostream>
#include <vector>
#include <math.h>

long long fibonacci_fast(long long n) {
    n = (n+2)%60;
    std::vector<int> F(n+1);

    F[0]=0;
    F[1]=1;
    int sum=1;
    for(int i=2;i<=n;i++){
        F[i]=(F[i-1]%10+ F[i-2]%10)%10;
    }
     if(F[n] == 0){
        return 9;
    }
    return (F[n]%10-1);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n);
}
