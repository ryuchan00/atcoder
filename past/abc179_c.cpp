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

// https://atcoder.jp/contests/past201912-open/tasks/past201912_g

int main() {
  ll N;
  cin >> N;

  ll ans = 0;
  int b_count = 0;

  // Aに1からN-1までの値を順番に代入して試す
  for (int A = 1; A < N; A++) {
    b_count = (int)((N - 1) / A);
    ans += b_count;
  }
  cout << ans << endl;
}
