#include <iostream>
#include <vector>

using std::vector;


int merge(vector<int> &arr, vector<int> &temp, int left,
          int mid, int right)
{
    int  i = left, j = mid, k = left;
    int number_of_inversions = 0;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            number_of_inversions = number_of_inversions + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return number_of_inversions;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
  long long number_of_inversions = 0;
  if (right > left){
  int ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  number_of_inversions += merge(a, b, left, ave+1, right);
  return number_of_inversions;
  }
  return number_of_inversions;
}
int mergeSort(vector<int> &arr, int array_size)
{
    vector<int>temp(array_size);
    return get_number_of_inversions(arr, temp, 0, array_size - 1);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << mergeSort(a, a.size()) << '\n';
}
