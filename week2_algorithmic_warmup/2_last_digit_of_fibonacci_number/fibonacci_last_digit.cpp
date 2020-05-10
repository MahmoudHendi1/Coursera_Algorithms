#include <iostream>
#include <vector>

int get_fibonacci_last_digit(int n) {
    std::vector<long long> F(n);
    if(n<=1){
    return n;
    }
    F[0]=1;
    F[1]=1;
    for(int i=2;i<n;i++){
        F[i]=(F[i-1]+F[i-2])%10;
    }
    return F[n-1];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit(n) << '\n';
    }
