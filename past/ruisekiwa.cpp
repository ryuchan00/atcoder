#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
void dump(vector<ll> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
}
void dump2(vector<vector<ll>> a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

bool has_bit(int n, int i) {
  return (n & (1 << i)) > 0;
}

// 累積和の練習

int main() {
  vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  const int N = 10;
  int sum[N];
  rep(i, N) {
    int s = 0;

    rep(j, i + 1) {
      s += A[j];
    }

    sum[i] = s;
  }
  rep(i, N) {
    /*
0
1
3
6
10
15
21
28
36
36
    */
    cout << sum[i] << endl;
  }
}
