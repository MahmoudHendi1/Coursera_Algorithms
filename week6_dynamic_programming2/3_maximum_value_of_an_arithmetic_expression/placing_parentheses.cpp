#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>


using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int numOfnum = (length + 1) / 2;
  vector<vector <int> >minArray(numOfnum,vector <int>(numOfnum,0));
  vector<vector <int> >maxArray(numOfnum,vector <int>(numOfnum,0));

  for (int i = 0; i < numOfnum; i++)
  {
	  minArray[i][i] = std::stoll(exp.substr(2*i,1));
	  maxArray[i][i] = std::stoll(exp.substr(2*i,1));
  }

  for (int s = 0; s < numOfnum - 1; s++)
  {
	  for (int i = 0; i < numOfnum - s - 1; i++)
	  {
		  int j = i + s + 1;
		  long long minVal = LLONG_MAX;
	      long long maxVal = LLONG_MIN;

		  for (int k = i; k < j; k++ )
	      {
			  long long a = eval(minArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  long long b = eval(minArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  long long c = eval(maxArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  long long d = eval(maxArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  minVal = min(minVal,min(a,min(b,min(c,d))));
			  maxVal = max(maxVal,max(a,max(b,max(c,d))));
	      }
		  minArray[i][j] = minVal;
		  maxArray[i][j] = maxVal;
	  }
  }
  return maxArray[0][numOfnum - 1];

}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
