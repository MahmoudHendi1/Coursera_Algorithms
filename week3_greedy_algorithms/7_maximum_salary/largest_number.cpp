#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool IsGreaterOrEqual(string digit,string maxDigit){
    int sz=std::min(digit.size(),maxDigit.size());
    for(int i=0;i<sz;i++){
        if(digit[i]<maxDigit[i])
            return false;
    }
    return true;
}


string largest_number(vector<string> a) {
  string result="";
  int index=0;
  sort(a.begin(),a.end());
  for(int i = a.size()-1; i >=0; i--) {
    string maxDigit="";
  for(int j = a.size()-1; j >=0; j--) {
    if(IsGreaterOrEqual(a[j],maxDigit)){
      maxDigit=a[j];
      index=j;
    }
  }
    result+=maxDigit;
    a.erase(a.begin()+index);
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
