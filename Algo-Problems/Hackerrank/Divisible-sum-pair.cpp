#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

bool isInt(float f);

using namespace std;


int main(){
  int n;
  int k;
  cin >> n >> k;
  vector<int> a(n);
  for(int a_i = 0;a_i < n;a_i++){
    cin >> a[a_i];
  }
  int counter = 0;
  for (int i = 0; i < n - 1; i++){
    for (int j = i + 1; j < n; j++){
      int sum = a[i] + a[j];
      float f = sum/k;
      if (isInt(f)){
	counter++;
      }
    }
  }
  cout << counter;
  return 0;
}

bool isInt(float f){
  return floor(f) == f;
}
