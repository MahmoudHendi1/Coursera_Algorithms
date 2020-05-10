#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    long long max_ind1=-1;
    for (int i = 0; i < n; ++i) {
       if(numbers[i]>=numbers[max_ind1])
            max_ind1=i;
    }
    int max_ind2=-1;
    for (int i = 0; i < n; ++i) {
       if(numbers[i]>=numbers[max_ind2] && i !=max_ind1)
            max_ind2=i;
    }
    max_product =(long long)numbers[max_ind2] *numbers[max_ind1];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
